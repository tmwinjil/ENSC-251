/**
* @file patient.cpp
* @author Takunda MWinjilo
* @Date 01/06/2018
* @version 1.0
* @section Creates an instance of patient from programmer entered data and outputs procedures and total costs
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ Takunda Mwinjilo ____ _____06/01/2018______________
//
// __

#include <iostream>
#include <string>

using namespace std;

class Patient
{
public:
	Patient(string first,string middle,string last,string add, string st, string zip, string phone, string emName,string emContact);
	
	void setFirstName(string first);
	void setMiddleName(string middle);
	void setLastName(string last);
	void setAddress(string add);
	void setState(string st);
	void setZipCode(string zip);
	void setPhoneNumber(string phone);
	void setEmergencyName(string emName);
	void setEmergencyContact(string emContact);

	string getFirstName();
	string getMiddleName();
	string getLastName();
	string getAddress();
	string getState();
	string getZipCode();
	string getPhoneNumber();
	string getEmergencyName();
	string getEmergencyContact();


private:
	string firstName;
	string middleName;
	string lastName;
	string address;
	string state;
	string zipCode;
	string phoneNumber;
	string emergencyName;
	string emergencyNumber;

};

class Procedure
{
public:

	Procedure(string procedure,string today,string doctor,int price);
		
	friend int procedureTotals(Procedure p1,Procedure p2,Procedure p3);

	void setProcedureName(string procedure);
	void setDate(string today);
	void setPractitioner(string doctor);
	void setCharge(int price);

	string getProcedureName();
	string getDate();
	string getPractitioner();
	int getCharge();
	
private:
	string procedureName;
	string practitionerName;
	string date;
	int charge;

};

 void displayProcedure(Procedure p);


int main()
{
	Patient tk("Takunda","Letser","Mwinjilo","8888 University Drive","British Columbia","V5A1S6","6046185470","Chengetai Chisina","6087738290");
	Procedure prod1("Physical Exam","Friday 1 June 2018", "Dr. Irvine",250.00);
	Procedure prod2("X-ray","Friday 1 June 2018", "Dr. Jamison",500.00);
	Procedure prod3("Blood test","Friday 1 June 2018", "Dr. Smith",200.00);

	cout<<"obtaining patient info..."<<endl<<endl
		<<"Name: "<<tk.getFirstName()<<" "<<tk.getMiddleName()<<" "<<tk.getLastName()<<endl
		<<"Address: "<<tk.getAddress()<<", "<<tk.getState()<<", "<<tk.getZipCode()<<endl
		<<"Phone Number: "<<tk.getPhoneNumber()<<endl
		<<"Emergency Contact: "<<tk.getEmergencyName()<<endl
		<<"Emergency Phone: "<<tk.getEmergencyContact()<<endl<<endl;

	
	cout<<"obtaining procedure details..."<<endl<<endl
		<<"Procedure 1:"<<endl;
		displayProcedure(prod1);
	cout<<"Procedure 2:"<<endl;
		displayProcedure(prod2);
		cout<<"Procedure 3:"<<endl;
		displayProcedure(prod3);
		
		cout<<"The total cost for all 3 procedures will be: $"<<procedureTotals(prod1,prod2,prod3)<<endl;
		return 1;
}

//Patient class functions being defined

//Constrictor
Patient::Patient(string first,string middle,string last,string add, string st, string zip, string phone, string emName,string emContact)
{
	 firstName=first;
	 middleName=middle;
	 lastName=last;
	 address=add;
	 state=st;
	 zipCode=zip;
	 phoneNumber=phone;
	 emergencyName=emName;
	 emergencyNumber=emContact;
}

//Mutators for Patient
	void Patient::setFirstName(string first)
	{firstName=first;}
	void Patient::setMiddleName(string middle)
	{middleName=middle;}
	void Patient::setLastName(string last)
	{lastName=last;}
	void Patient::setAddress(string add)
	{address=add;}
	void Patient::setState(string st)
	{state=st;}
	void Patient::setZipCode(string zip)
	{zipCode=zip;}
	void Patient::setPhoneNumber(string phone)
	{phoneNumber=phone;}
	void Patient::setEmergencyName(string emName)
	{emergencyName=emName;}
	void Patient::setEmergencyContact(string emContact)
	{emergencyNumber=emContact;}

	//Accessors for Patient
	string Patient::getFirstName()
	{ return firstName;}
	string Patient::getMiddleName()
	{return middleName;}
	string Patient::getLastName()
	{return lastName;}
	string Patient::getAddress()
	{return address;}
	string Patient::getState()
	{return state;}
	string Patient::getZipCode()
	{return zipCode;}
	string Patient::getPhoneNumber()
	{return phoneNumber;}
	string Patient::getEmergencyName()
	{return emergencyName;}
	string Patient::getEmergencyContact()
	{return emergencyNumber;}

	//Procedure class functions being defined

	//Constructor
		Procedure::Procedure(string procedure,string today,string doctor,int price)
		{
			procedureName=procedure;
			date=today;
			practitionerName=doctor;
			charge=price;
		}


	//Mutators
	void Procedure::setProcedureName(string procedure)
	{procedureName=procedure;}
	void Procedure::setDate(string today)
	{date=today;}
	void Procedure::setPractitioner(string doctor)
	{practitionerName=doctor;}
	void Procedure::setCharge(int price)
	{charge=price;}

	//Accessors
	string Procedure::getProcedureName()
	{return procedureName;}
	string Procedure::getDate()
	{return date;}
	string Procedure::getPractitioner()
	{return practitionerName;}
	int Procedure::getCharge()
	{return charge;}


	int procedureTotals(Procedure p1,Procedure p2,Procedure p3)
	{
		int total=0;
		total=p1.charge+p2.charge+p3.charge;
		return total;
	}

	void displayProcedure(Procedure p)
	{
		cout<<"Name: "<<p.getProcedureName()<<endl
			<<"Date: "<<p.getDate()<<endl
			<<"Practitioner: "<<p.getPractitioner()<<endl
			<<"Charge: $"<<p.getCharge()<<endl<<endl;
	}

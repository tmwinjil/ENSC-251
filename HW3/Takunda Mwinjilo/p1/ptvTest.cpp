#include<iostream>
#include<string>
using namespace std;
#include "ptv.h"

int main()
{
	string manufacturer;
	int cylinders= 0;
	string name;

	cout<<"COMMENCING CLASS TESTS"<<endl<<endl;

	//Person Test

	cout<<"Time to make some people"<<endl<<endl;
	cout<<"First the full constructor"<<endl;
	Person p1("Damien");
	cout<<"Person 1 is called: "<<p1.getName()<<endl;
	cout<<"If Damien was the name returned then the constructor and function work"<<endl<<endl;

	cout<<"Great Now let's test the assignment operator"<<endl;
	Person p2;
	cout<<"Enter any name"<<endl;
	cin>>p2;
	cin.clear();
	cin.ignore(256,'\n');
	cout<<"Person 2 is called: "<<p2.getName()<<endl<<endl;
	cout<<"Finally we test the copy assignment"<<endl<<endl
		<<"We will try assigning person 2 to person 1"<<endl;

	p1 = p2;
	cout<<"Person 1 is "<<p1.getName()<<endl
		<<"Person 2 is "<<p2.getName()<<endl<<endl;

	cout<<"we have now shown that the Person class works"<<endl;

	//Vehicle Test

	cout<<"Now we will test Vehicle class"<<endl<<endl;
	cout<<"First we try the full constructor"<<endl;
	cout<<"Enter a manufacturer name"<<endl;
	cin>>manufacturer;
	cout<<"Enter the number of cylinders in the vehicle"<<endl;
	cin>>cylinders;
	cout<<"Enter a name"<<endl;
	cin>>name;
	Vehicle v1(manufacturer,cylinders,name);
	cout<<endl<<"Vehicle1:"<<endl<<v1<<endl<<endl;

	cout<<"Now the set functions"<<endl;
	Vehicle v2;
	v2.setManufacturer(manufacturer);
	v2.setCylinders(cylinders);
	v2.setOwner(name);
	cout<<"Vehicle 2: "<<endl
		<<"manufacturer: "<<v2.getManufacturer()<<endl
		<<"Number of Cylinders: "<<v2.getCylinders()<<endl
		<<"Owner name: "<<v2.getOwner()<<endl<<endl;

	cout<<"we have now shown that the Vehicle class works"<<endl;



	//Truck Test

	cout<<"Finally the Truck class"<<endl<<endl;
	cout<<"Please enter a new manufacturer"<<endl;
	cin>>manufacturer;
	cout<<"Enter the number of cyinders"<<endl;
	cin>>cylinders;
	cout<<"Enter a new owner name"<<endl;
	cin>>name;
	Truck t1(manufacturer, cylinders,name,12.7,18);
	cout<<"Truck 1"<<endl<<t1<<endl<<endl;
	cout<<"Testing output functions with pre-made truck"<<endl;
	Truck t2("Toyota",4,"Damien",15,18);
	cout<<"Truck 2: "<<endl
		<<"manufacturer: "<<t2.getManufacturer()<<endl
		<<"Number of Cylinders: "<<t2.getCylinders()<<endl
		<<"Owner name: "<<t2.getOwner()<<endl
		<<"Load Capacity in tonnes: "<<t2.getLoadC()<<endl
		<<"Towing Capacity in tonnes: "<<t2.getTowingC()<<endl<<endl;

	t1 = t2;
	cout<<"Truck 1: "<<endl<<t1<<endl;
	cout<<"Truck 2: "<<endl<<t2<<endl<<endl;

	cout<<"Both trucks should be equal"<<endl<<endl;

	cout<<"we have now shown that the Truck class works"<<endl;


	cout<<"TEST OVER"<<endl;

	return 1;


}

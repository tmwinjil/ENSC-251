/**
* @file stock.cpp
* @author TAKUNDA MWINJILO
* @Date 07/19.2018
* @version 1.0
* @section Program that reads gas data from a file and outputs a series of calculations and 2 files ordered by price
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ TAKUNDA MWINJILO ____ _____07/20/2018______________
//
// ____301344066_____

#include<iostream>
#include<string>
#include<set>
#include<fstream>
#include<string>
using namespace std;

//DATE CLASS DEFINITION
class Date
{
public: 
//Constructors
Date();
Date(int d, int m, int y);

//Accessors
int getYear();
int getMonth();

//Overloaded operators
Date& operator = (const Date& rtSide);
friend istream& operator >>(istream& inStream,Date& theDate);
friend ostream& operator <<(ostream& outStream,const Date& theDate);
friend bool operator <(const Date& A, const Date& B);
friend bool operator ==(const Date& lhs, const Date& rhs);

private:
 int day;
 int month;
 int year;
};

//STOCK CLASS DEFINITION
class Stock
{
public:
//Constructors
Stock();
Stock(Date d,double o,double h,double l,double c,double ac,long int v);

//Accessors
int getMonth();
int getYear();
double getPrice();

//Overloaded operators
Stock& operator = (const Stock& rtSide);
friend istream& operator >>(istream& inStream,Stock& stockObject);
friend ostream& operator <<(ostream& outStream,const Stock& stockObject);
friend bool operator <(const Stock& A, const Stock& B);

private:
Date date;
double open;
double high;
double low;
double close;
double adjClose;
long int volume;
};


int main()
{
	ifstream dataFile;
	ofstream highToLow("HighToLow.csv");
	ofstream lowToHigh("LowToHigh.csv");
	set<Stock> stocks;
	Stock data;

	int byMonthCounter = 1;
	int prevMonth = 0;
	double byMonthTotal = 0;
	int byYearCounter = 1;
	int prevYear = 0;
	double byYearTotal = 0;
	double high = 0;
	double low = 1000;
	double price;

	string s;
	string month[12] = {"January", "February", "March", "April", "May","June", "July", "August", "September", "October", "November", "December"};

	dataFile.open("StockPrices.csv");
	cout<<"Now reading file"<<endl;
	getline(dataFile,s);

	//First line of data
	dataFile>>data;
	prevMonth = data.getMonth();
	prevYear = data.getYear();
	byMonthTotal = data.getPrice();
	byYearTotal = data.getPrice();
	high = data.getPrice();
	low = high;


	//The rest of the data
	while(!dataFile.eof())
	{
		dataFile>>data;
		stocks.insert(data);

		if (data.getMonth() != prevMonth)
		{
			cout<<month[prevMonth-1]<<" "<<prevYear<<" average: $"<<byMonthTotal/byMonthCounter<<endl;
			byMonthCounter = 0;
			byMonthTotal = 0;

		}
		if (data.getYear() != prevYear)
		{
			cout<<prevYear<<" AVERAGE: $"<<byYearTotal/byYearCounter<<endl
				<<"High: $"<<high<<endl
				<<"low: $"<<low<<endl<<endl;
			byYearCounter = 0;
			byYearTotal = 0;
			high = 0;
			low = 1000;
		}
		
			byMonthCounter++;
			byYearCounter++;
			price = data.getPrice();
			byMonthTotal += price;
			byYearTotal += price;
			if(price>high)
				high = price;
			if(price<low)
				low = price;

			prevMonth = data.getMonth();
			prevYear = data.getYear();
		
	}
	
	cout<<"The average price for "<<month[prevMonth-1]<<prevYear<<" is:"<<byMonthTotal/byMonthCounter<<endl
		<<prevYear<<" AVERAGE: $"<<byYearTotal/byYearCounter<<endl
		<<"High: $"<<high<<endl
		<<"low: $"<<low<<endl;

	lowToHigh<<s<<endl;
	for(auto p: stocks)
	{
		lowToHigh<<p<<endl;
	}
	lowToHigh.close();

	highToLow<<s<<endl;
	set<Stock>::reverse_iterator rp;
	for (rp = stocks.rbegin(); rp!= stocks.rend(); rp++)
	{
		highToLow<<*rp<<endl;
	}
	highToLow.close();


	return 1;
}

//DATE IMPLEMENTATION

//Blank Constructor
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}
/**
*@brif Full Constructor
*@param d represents the day
*@param m represents the month
*@param y represents the year
*/
Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

//Accessors
int Date::getYear()
{
	return year;
}
int Date:: getMonth()
{
	return month;
}

//Overloaded Operators
Date& Date::operator = (const Date& rtSide)
{
	if(this != &rtSide)
	{
		this->day = rtSide.day;
		this->month = rtSide.month;
		this->year = rtSide.year;
	}
	return *this;

}
istream& operator >>(istream& inStream,Date& theDate)
{
	char c;
	inStream>>theDate.month>>c>>theDate.day>>c>>theDate.year;
	return inStream;
}
ostream& operator <<(ostream& outStream,const Date& theDate)
{
	outStream<<theDate.month<<"/"<<theDate.day<<"/"<<theDate.year;
	return outStream;
}
bool operator ==(const Date& lhs, const Date& rhs)
{
	if(lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year)
		return true;

	return false;
}


//STOCK CLASS IMPLEMENTATION

//Blank Constructor
Stock::Stock()
{
	Date d;
	date = d;
	open = 0;
	high = 0;
	low = 0;
	close = 0;
	adjClose = 0;
	volume = 0;

}
/**
*@brif Full Constructor
*@param d represents column 1 of the data (date)
*@param o represents column 2 of the data( the open Price)
*@param h represents column 3 of the data (high price)
*@param h represents column 4 of the data (low price)
*@param h represents column 5 of the data (close price)
*@param h represents column 6 of the data (adj close price)
*@param h represents column 7 of the data (volume of gas)
*/
Stock::Stock(Date d,double o,double h,double l,double c,double ac,long int v)
{
	date = d;
	open = o;
	high = h;
	low = l;
	close = c;
	adjClose = ac;
	volume = v;

}

//Accessors
int Stock::getYear()
{
	return date.getYear();
}
int Stock::getMonth()
{
	return date.getMonth();
}
double Stock::getPrice()
{
	return high;
}

//Overloaded operators
Stock& Stock::operator = (const Stock& rtSide)
{
		if(this != &rtSide)
	{
		this->date = rtSide.date;
		this->open = rtSide.open;
		this->high = rtSide.high;
		this->low = rtSide.low;
		this->close = rtSide.close;
		this->adjClose=  rtSide.adjClose;
		this->volume = rtSide.volume;
	}
	return *this;
}
istream& operator >>(istream& inStream,Stock& stockObject)
{
	char c;
	inStream>>stockObject.date>>c
			>>stockObject.open>>c
			>>stockObject.high>>c
			>>stockObject.low>>c
			>>stockObject.close>>c
			>>stockObject.adjClose>>c
			>>stockObject.volume;
	return inStream;
}
ostream& operator <<(ostream& outStream,const Stock& stockObject)
{
	outStream<<stockObject.date<<","
			<<stockObject.open<<","
			<<stockObject.high<<","
			<<stockObject.low<<","
			<<stockObject.close<<","
			<<stockObject.adjClose<<","
			<<stockObject.volume;
	return outStream;
}
bool operator <(const Stock& A, const Stock& B)
{
	if(A.high < B.high)
		return true;

	return false;
}


/**
* @file books.cpp
* @author Takunda Mwinjilo
* @Date 09/07/2018
* @version 1.0
* @section Program that simulates a book database
*/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ TAKUNDA MWINJILO ____ _____09/07/2018______________
//
// ____ 301344066 ______
//

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Books
{
public:
//Constructors
Books();
Books(string auth, string tit, string pub);

//Output

//Overloaded operators
friend bool operator ==(const Books& lhs, const Books& rhs);
friend ostream& operator <<(ostream& outStream,const Books& book);
friend bool operator <(const Books& A, const Books& B);

private:
string author;
string title;
string publicationYear;

};

void printBooks(vector<Books>& b);
void getInput(string& data);
void addBook(string author, string title, string date, vector<Books>& database);
string upperCase(string data);

int main()
{
vector<Books> database;
int choice = 0;
bool quit = 0;
string title, author, date; 

while(quit == 0)
{
	cout<<"Please pick one of the following choices"<<endl
		<<"1. Add a new book"<<endl
		<<"2. Print a book list"<<endl
		<<"3. Quit program"<<endl;
	while(1)
	{
		if(!(cin>>choice))
		{	
			cout<<"Please use numbers only"<<endl;
		}
		else if(choice > 3 || choice < 1)
		{
			cout<<"Please pick from the choices"<<endl;
		}
		else
			break;

		cin.clear();
		cin.ignore(256,'\n');
	}

	switch(choice)
	{
	case 1: {
				bool wrongDate = 0;

				cout<<"Enter a book title:"<<endl;
				getInput(title);
				cout<<"Enter the Book Author in the form <LASTNAME , FIRSTNAME>"<<endl;
				getInput(author);
				while (1)
				{
					wrongDate = 0;
					cout<<"Enter the year of publication"<<endl;
					cin>>date;
					for (unsigned i = 0; i <date.length(); i ++)
					{
						if (isdigit(date[i]) == 0)
						{
							cout<<"wrong date format. Please try again"<<endl;
							wrongDate = 1;
							break;
						}
					}
					if (wrongDate == 0)
					{
						break;
					}
				}
				addBook(author,title,date, database);
				cout<<endl;
				break;
			}
	case 2: printBooks(database);
			break;
	
	case 3:	quit = 1;
			break;
	
	}
}
cout<<"Ending Program"<<endl;
return 1;

}
//IMPLEMENTATION OF BOOKS CLASS

//Blank constructor for class books
Books::Books()
{
	author = " ";
	title = " ";
	publicationYear = " ";
}

/*
*@brief Full constructor for Books Class
*@param auth holds the authors name
*@param tit holds the book Title
*@param pub holds the year the book was published
*/
Books::Books(string auth, string tit, string pub)
{
	author = auth;
	title = tit;
	publicationYear = pub;
}

bool operator ==(const Books& lhs, const Books& rhs)
{
	string authL, authR, titL, titR;
	authL = upperCase(lhs.author);
	authR = upperCase(rhs.author);
	titL = upperCase(lhs.title);
	titR = upperCase(rhs.title);

	if (authL == authR && titL == titR && lhs.publicationYear == rhs.publicationYear)
		return true;

	return false;
}

ostream& operator <<(ostream& outStream,const Books& book)
{
	outStream<<book.author<<".  "<<"\""<<book.title<<"\""<<".  "<<"("<<book.publicationYear<<").";
	return outStream;
}
bool operator <(const Books& A, const Books& B)
{
	string a,b;
	a = upperCase(A.author);
	b = upperCase(B.author);
	if (a < b)
		return true;

	return false;
}
//END OF BOOKS CLASS IMPLEMENTATION


//Sorts the books contained in a vector by author in alphabetical order and outputs them
void printBooks(vector<Books>& b)
{
		if(b.size() == 0)
	{	
		cout<<"No books have been added yet"<<endl;
		return;
	}
	cout<<"The books entered so far, ordered alphabetically by author are: "<<endl;
	sort(b.begin(), b.end());
	for(unsigned i = 0; i < b.size(); i++)
	{
		cout<<i + 1<<")  "<<b[i]<<endl;
	}
}

//Allows for the entire line of text to be input
void getInput(string& data)
{
	string a,b;
	cin>>a;
	getline(cin,b);
	data = a + b;

}

//Adds book to Database if it is not already there
void addBook(string author, string title, string date, vector<Books>& database)
{
	Books next(author,title,date);
	bool found = 0;

	for (unsigned i = 0; i < database.size(); i++)
	{
		if (next == database[i])
		{
			cout<<"This book is already in the database"<<endl;
			found = 1;
		}
	}

	if (found == 0)
		database.push_back(next);
}

//Converts string to uppercase
string upperCase(string data)
{
	for(int i = 0; i < data.length(); i++)
	{
		data[i] = toupper(data[i]);
	}
	return data;
}

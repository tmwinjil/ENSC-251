/**
* @file XX.cpp
* @author FIRSTNAME LASTNAME
* @Date DATE
* @version 1.0
* @section DESCRIPTION
**/
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// _____ TAKUNDA MWINJILO____ _____06/22/2018______________
//
// __301344066___

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;


int ladder(string start, string end,vector <string> words);
//precondition: words is not an empty vector
//postcondition: word ladder is printed

int main()
{
string start;
string end;
string s;
unsigned length;
int ladderFound=0;
char done; // test variable

int arraySize = 0;
int startFound = 0;
int endFound = 0;
//string filename="words.txt";
//ifstream words (filename.c_str());
ifstream words ("words.txt");

vector <string> list;
cout<<"Please enter the first word in the ladder: ";
cin>>start;
cout<<endl<<"Please enter the last word in the ladder: ";
cin>>end;
cout<<endl;


//verify using length of string
if(start.length() != end.length())
{
        cout<<"These words have a different length. Word ladder cannot be formed"<<endl;
        return 0;
}

length = start.length();


//change words to lower case to match file and letter check
for(unsigned i = 0; i < length;i++)
{
        if(!isalpha(start[i]) || start[i] == ' ')
        {
                cout<<"Starting word is INVALID"<<endl;
                return 0;
        }
        else if(!isalpha(end[i]) || end[i] == ' ')
        {
                cout<<"finishing word is INVALID"<<endl;
        }
        start[i] = tolower(start[i]);
        end[i] = tolower(end[i]);
}

cout<<"Computing word list..."<<endl<<endl;

//No ladder if words are the same
if(start == end)
{
        cout<<"Words are the same. No ladder can be formed"<<endl;
        return 1;
}

//Check for words in file and create vector of words of the same size
while(!(words.eof()))
{
        words>>s;

        if(s.length() != length)
        {
                        continue;
        }
        list.push_back(s);
        arraySize++;

        if (s == start)
        {
                startFound = 1;
        }
        else if (s == end)
        {
                endFound = 1;
        }
}


if (arraySize == 0)
{
        cout<<"These words are too long. No ladder can be formed"<<endl;
        return 0;
}
else if(startFound == 0)
{
        cout<<"\""<<start<<"\" not found. No Ladder can be formed"<<endl;
        return 0;
}
else if(endFound == 0)
{
        cout<<"\""<<start<<"\" not found. No Ladder can be formed"<<endl;
        return 0;
}


//create ladder
ladderFound = ladder(start,end,list);
words.close();

                if(ladderFound == 0)
                {
                        cout<<"No ladder could be found"<<endl;
                        cin>>done; // delay program close
						
                        return 0;
                }
                else
                {
                        cout<<end<<endl;
                        cin>>done; // delay program close
                        return 1;
                }

}

/**
*@brief Recursive function that finds word ladder
*@param start represents the correct start word
@param end represents the final word in the ladder
@param words is the list of possible words for this ladder
**/
int ladder(string start, string end, vector <string> words)
{
int wordlength = end.length();
int found = 0;
string e = end;
string s = start;


if (start == end)	//base case
{
        return 1;
}


for(int i = wordlength-1; i >= 0;i--)
{
        if(e[i] == s[i])
        {
                continue;
        }

        for(unsigned j = 0; j < words.size();j++)
        {
                e[i]=s[i];
                if (e == words[j])
                {
                    found = ladder(s,e,words);
                }
                if (found == 1)
                {
					 cout<<e<<endl;
                     return 1;
                }

        }
        e = end;
}


if (found == 0)
{
        return 0;
}
return 1;

}

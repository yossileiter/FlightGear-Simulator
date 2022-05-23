#include "Lexer.hpp"

Lexer* Lexer::instance = 0;
Lexer* Lexer::getInstance()
{
	if (!instance) instance = new Lexer;
	return instance;
}

bool Lexer::FindIfElementExist(vector<string> v, string element)
{    
    vector<string>::iterator it = find(v.begin(), v.end(), element.c_str());
    if (it != v.end()) return 1;
    else return 0;
}

int Lexer::FindElementLocation(vector<vector<string>> v, string element)
{
    for (size_t rows = 0; rows < AllLinesSeparated.size(); rows++)
    {
        if (FindIfElementExist(AllLinesSeparated[rows], element)) return rows;
    }
    return 0;
}

void Lexer::ReadInstructions(string FilePath) //read the instructions file and split to lines
{
    fstream newfile;
    newfile.open(FilePath,ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) //checking whether the file is open
    { 
        string line;
        while(getline(newfile, line)) //read data from file object and put it into string.
        {   
            AllLines.push_back(line);
        }
        newfile.close(); //close the file object.
        // PrintVector(AllLines);
    }
}

void Lexer::SplitLine(string s) //split a line into words
{	
    string temp = "";
    for(int i=0 ;i<s.length(); ++i)
    {
        if(s[i]==' ') v.push_back(temp), temp = "";
        else { temp.push_back(s[i]); }		
    }
    v.push_back(temp);	
};


void Lexer::PrintVector(vector<string> v) //print a vector
    {
        for(int i=0;i<v.size();++i) cout<<v[i]<<endl;
        cout<<"\n";
    }

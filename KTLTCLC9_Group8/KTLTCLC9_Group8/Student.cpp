#include "Struct.h"
#include "Class.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

void inputStudent(Student *&newStu) 
{

	cout << "Enter student's ID: ";
    cin.ignore(100, '\n');
	getline(cin, newStu->ID);

	cout << "Enter student's name: ";
    cin.ignore(1000, '\n');
	getline( cin, newStu->name);

	cout << "Enter student's date of birth(dd/mm/yyyy): ";
    string temp;
    int posOfSlash[2];
    int i=0;
    cin.ignore(1000, '\n');
    getline(cin, temp);
    for(int k=0; k< temp.size(); k++)
    {
        if(temp[k]=='/')
            posOfSlash[i++]=k;
    }
    cout<<posOfSlash[0]<<posOfSlash[1];
    newStu->DOB.day=atoi(temp.substr(0,posOfSlash[0]).c_str());
    newStu->DOB.month=atoi(temp.substr(posOfSlash[0]+1,posOfSlash[1]-posOfSlash[0]-1).c_str());
    newStu->DOB.year=atoi(temp.substr(posOfSlash[1]+1,temp.size()-posOfSlash[1]-1).c_str());
	
    cout << "Enter student's gender (0 for male, 1 for female): ";
	cin>>newStu->gender;
}

void addNewStudent(Student*& pStudent, string yearName, string className, Student *& newStu)
{
    
    string dirD="C:\\Github\\KTLTPJ\\KTLT21CLC9-Group8\\Data\\YearName\\" + yearName + "\\" + className + "\\Student.txt";
    fstream output;
    output.open(dirD, ios::out);

    if (pStudent == nullptr) 
    {
		pStudent = newStu;
	}
	else 
    {
		Student* pCur = pStudent;
		while (pCur -> studentNext != nullptr) 
        {
			pCur = pCur -> studentNext;
		}
		pCur -> studentNext = newStu;
	}
    Student* pCur = pStudent;
    pCur=pStudent;
    while (pCur != nullptr) 
        {
			output << pCur -> ID << ", " << pCur ->name << ", " << pCur -> DOB.year << "-" << pCur -> DOB.month << "-" << pCur -> DOB.day << ", " << pCur -> gender << '\n';
            pCur=pCur->studentNext;
		}
    output.close();
}

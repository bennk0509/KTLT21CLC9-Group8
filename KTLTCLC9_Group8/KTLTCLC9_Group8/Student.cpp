#include "Struct.h"
#include "Student.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

void inputStudent(Student *&newStu) 
{
	cout << "Enter student's ID: ";
	getline(newStu->ID, cin);

	cout << "Enter student's name: ";
	getline(newStu->name, cin);

	cout << "Enter student's date of birth(dd/mm/yyyy).\n";
    int stack=0;
    string temp;
    int posOfSlash[2];
    int k=0;
    getline(temp, cin);
    for(int i=0; i< temp.size()); i++;
    {
        if(temp[i]=="/") posOfSlash[k++]=i;
    }
    newStu->DOB.day=atoi(temp.substr(0,posOfSlash[0]).c_str());
    newStu->DOB.month=month(temp.substr(posOfSlash[0]+1,posOfSlash[1]-posOfSlash[0]-1).c_str());
    newStu->DOB.day=year(temp.substr(osOfSlash[1]+1,4).c_str());
	
    cout << "Enter student's gender (0 for male, 1 for female): ";
	cin>>newStu->gender;
	system("cls");
}


void addNewStudent(Student*& pStudent, string yearName, string className, Student *& newStu)
{
    string dirD="C:\\Github\\CS162FinalProject\\Data\\" + yearName + "\\" + className + "\\Student.txt"
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
    pCur=pStudent;
    while (pCur != nullptr) 
        {
			output << pCur -> studentID << ", " << pCur -> Name << ", " << pCur -> DOB.year << "-" << pCur -> DOB.month << "-" << pCur -> DOB.day << ", " << pCur -> gender << '\n';
            pCur=pCur->studentNext;
		}
    output.close();
}

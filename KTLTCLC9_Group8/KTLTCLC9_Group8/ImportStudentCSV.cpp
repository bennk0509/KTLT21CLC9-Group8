#include <iostream>
#include <fstream>
using namespace std;

#include "Struct.h"


Student* inputStudent(ifstream& studentcsv)
{
	int count = 0;
	Student *pS = new Student;
	string s;
	getline(studentcsv, s);
	int size = s.length();
	if (s[1] != ',')
		pS->ID = s.substr(3, 8);
	else
		pS->ID = s.substr(2, 8);
	pS->gender = s[size - 1] - 48;
	for (int i = size - 3; i > 0; i--)
	{
		if (s[i] == ',')
			break;
		count++;
	}
	pS->classname = s.substr(size - count - 2, count);
	pS->BOD.day = stoi(s.substr(size - count - 5, 2));
	pS->BOD.month = stoi(s.substr(size - count - 8, 2));
	pS->BOD.year = stoi(s.substr(size - count - 13, 4));
	int k = count;
	count = 0;
	for (int i = size - k - 15; i > 0; i--)
	{
		if (s[i] == ',') break;
		count++;
	}
	if (s[1] != ',')
		pS->name = s.substr(12, count);
	else
		pS->name = s.substr(11, count);
	return pS;
}

bool existedCheck(Student* pStudent, Student* student)
{
	Student* pCur = pStudent;
	while (pCur != nullptr)
	{
		if (pCur->ID == student->ID)
			return false;
		pCur = pCur->studentNext;
	}
	return true;
}

void importStudentCSV(Student*& pStudent, ifstream& studentcsv)
{
	Student* sCur = pStudent;
	while (studentcsv.peek() != EOF)
	{
		if (pStudent == nullptr)
		{
			pStudent = inputStudent(studentcsv);
			pStudent->studentNext = nullptr;
			sCur = pStudent;
		}
		else
		{
			Student* check = inputStudent(studentcsv);
			if (existedCheck(pStudent, check) == true)
			{
				sCur->studentNext = check;
				sCur = sCur->studentNext;
				sCur->studentNext = nullptr;
			}
			else sCur->studentNext = nullptr;
		}
	}
}

void exportStudent(Student* pStudent, fstream& fout)
{
	Student* pCur = pStudent;
	int count = 0;
	if (pCur == nullptr)
	{
		cout << "ERROR";
		return;
	}
	while (pCur != nullptr)
	{
		fout << count++ << ",";
		fout << pCur->name << ",";
		fout << pCur->ID << ",";
		fout << pCur->BOD.year << "-" << pCur->BOD.month << "-" << pCur->BOD.day << ",";
		fout << pCur->classname << ",";
		fout << pCur->gender << "," << endl;
		pCur = pCur->studentNext;
	}
		
}

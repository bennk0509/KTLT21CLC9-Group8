#include <iostream>
#include "Struct.h"
#include "Class.h"
#include "Course.h"
#include "Staff.h"
#include "System.h"
#include "Student.h"
using namespace std;

void cont(char& contchar, bool& login)
{
	do
	{
		cout << "Do you want to continue? (y/n): ";
		cin >> contchar;
		system("cls");

	} while (contchar != 'y' && contchar != 'n');
	if (contchar == 'n')
		login = false;
}

bool changeYear(Year*& pYear, string& yearname, Year* &curYear, bool &yearcheck)
{
	curYear = pYear;
	do
	{
		system("cls");
		cout << "Input year (Format: 20xx): ";
		cin.ignore(1000, '\n');
		cin >> yearname;
		if (yearname.length() != 4 || atoi(yearname.c_str()) == 0)
		{
			cout << "Format is not correct, please try again";

		}
	} while (yearname.length() != 4 || atoi(yearname.c_str()) == 0);
	if (pYear == nullptr)
	{
		cout << "This year is not exist.";
		return false;
	}
	else
	{
		if (pYear->yearNext == nullptr)
		{
			if (pYear->YearName.compare(yearname) == 0)
			{
				yearcheck = true;
				curYear = pYear;
			}
		}
		else
		{
			curYear = pYear;
			while (curYear != nullptr)
			{
				if (curYear->YearName.compare(yearname) == 0)
				{
					yearcheck = true;
					break;
				}
				curYear = curYear->yearNext;
			}
		}
	}
	if (!yearcheck && pYear != nullptr)\
	{
		cout << "This year is not exist.";
		return false;
	}
	return true;
}

void changeSemester(Year* pYear, Semester*& curSemester, string& semesterName, bool &semestercheck)
{
	do
	{
		cout << "Input semester name (1,2 or 3): ";
		cin >> semesterName;
		if (semesterName != "1" && semesterName != "2" && semesterName != "3")
		{
			cout << "Incorrect input, please try again\n";
		}
	} while (semesterName != "1" && semesterName != "2" && semesterName != "3");

	if (pYear->pSemester == nullptr)
	{
		cout << "This semester is not exist.";
	}
	else
	{
		if (pYear->pSemester->semesterNext == nullptr)
		{
			if (pYear->pSemester->semesterName.compare(semesterName) == 0)
			{
				semestercheck = true;
				curSemester = pYear->pSemester;
			}
		}
		else
		{
			curSemester = pYear->pSemester;
			while (curSemester != nullptr)
			{
				if (curSemester->semesterName.compare(semesterName) == 0)
				{
					semestercheck = true;
					break;
				}
				curSemester = curSemester->semesterNext;
			}
		}
	}
	if (!semestercheck && pYear->pSemester != nullptr)
		cout << "This semester is not exist.";
}

//void loadData(Year*& pYear, ifstream &yearin)		
//{
//	Year* curYear = pYear;
//	while (yearin.peek() != EOF)
//	{
//		string yearName;
//		yearin >> yearName;
//		CreateNewYear(pYear, yearName, 0);
//		Year* curYear = pYear;
//		while (curYear->YearName.compare(yearName) != 0) 
//			curYear = curYear->yearNext;
//		string classdir = "";
//		ifstream classin(classdir);
//		while (classin.peek() != EOF)
//		{
//			string className;
//			classin >> className;
//			createNewClass(curYear->pClass, curYear->YearName, className,0);
//			Class* curClass = curYear->pClass;
//			while (curClass->className.compare(className) != 0)
//				curClass = curClass->classNext;
//			string studentdir = "";
//			ifstream studentin(studentdir);
//			while (studentin.peek() != EOF)
//			{
//				int count = 0;
//				Student* pS = new Student;
//				string s;
//				studentin.ignore(1000, '\n');
//				getline(studentin, s);
//				int size = s.length();
//				if (s[1] != ',')
//					pS->ID = s.substr(3, 8);
//				else
//					pS->ID = s.substr(2, 8);
//				pS->gender = s[size - 1] - 48;
//				for (int i = size - 3; i > 0; i--)
//				{
//					if (s[i] == ',')
//						break;
//					count++;
//				}
//				pS->classname = s.substr(size - count - 2, count);
//				pS->DOB.day = stoi(s.substr(size - count - 5, 2));
//				pS->DOB.month = stoi(s.substr(size - count - 8, 2));
//				pS->DOB.year = stoi(s.substr(size - count - 13, 4));
//				int k = count;
//				count = 0;
//				for (int i = size - k - 15; i > 0; i--)
//				{
//					if (s[i] == ',') break;
//					count++;
//				}
//				if (s[1] != ',')
//					pS->name = s.substr(12, count);
//				else
//					pS->name = s.substr(11, count);
//				
//
//				
//			}
//
//		}
//	}
//
//}

void inputNewCourse(Course*& newCourse)
{
	cout << "Course ID: ";
	cin >> newCourse->id;
	cout << "Course name: ";
	cin >> newCourse->name;
	cout << "Course's lecturer's name: ";
	cin >> newCourse->lecturerName;
	cout << "Number of credits: ";
	cin >> newCourse->numberOfCredits;
	cout << "Course date 1: ";
	cin >> newCourse->date.d1;
	cout << "Course date 2: ";
	cin >> newCourse->date.d2;
	cout << "Course shift 1: ";
	cin >> newCourse->date.s1;
	cout << "Course shift 2: ";
	cin >> newCourse->date.s2;
	cout << "Course max student: ";
	cin >> newCourse->maxStudent;
}

bool logStudent(string account, Year* pYear, Student* &curStudent, Year* &currentYear)
{
	bool acccheck = false;
	if (pYear == nullptr)
	{
		cout << "This account does not exist.\n";
		return false;
	}
	Year* curYear = pYear;
	while (curYear != nullptr)
	{
		if (curYear->YearName.substr(curYear->YearName.length() - 2, 2).compare(account.substr(0, 2)) == 0)
		{
			acccheck = true;
			currentYear = curYear;
			break;
		}
		curYear = curYear->yearNext;
	}
	if (!acccheck)
	{
		cout << "This account does not exist.\n";
		return false;
	}
	Class* curClass = curYear->pClass;
	while (curClass != nullptr)
	{
		Student* curStu = curClass->pStudent;
		while (curStu != nullptr)
		{
			if (curStu->ID.compare(account) == 0)
			{
				curStudent = curStu;
				break;
			}
			curStu = curStu->studentNext;
		}
		curClass = curClass->classNext;
	}
	return true;
}
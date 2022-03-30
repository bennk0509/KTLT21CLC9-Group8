#include <iostream>
#include "Struct.h"
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

//void loadData(Year*& pYear, ifstream &yearin)			Not Done Yet!
//{
//	string cdir = "";
//	Year* curYear = pYear;
//	while (yearin.peek() != EOF)
//	{
//		if (pYear == nullptr)
//		{
//			pYear = new Year;
//			yearin >> pYear->YearName;
//			cdir = "C:\\Data\\YearName\\" + pYear->YearName + "\\Class.txt";
//			ifstream classin(cdir);
//			while (classin.peek() != EOF)
//			{
//
//			}
//		}
//	}
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
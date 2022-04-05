#include <iostream>
#include <fstream>
#include "Struct.h"

using namespace std;


void inputSemester(Semester* &pSemester, string semesterName, string yearName)
{
	pSemester = new Semester;
	cout << "Semester start day: ";
	cin >> pSemester->startDate.day;
	cout << "Semester start month: ";
	cin >> pSemester->startDate.month;
	cout << "Semester start year: ";
	cin >> pSemester->startDate.year;
	cout << "------------------------\n";
	cout << "Semester end day: ";
	cin >> pSemester->endDate.day;
	cout << "Semester end month: ";
	cin >> pSemester->endDate.month;
	cout << "Semester end year: ";
	cin >> pSemester->endDate.year;
	pSemester->semesterName = semesterName;
	pSemester->yearName = yearName;
}


bool CreateNewSemester(Semester* &pSemester, string yearName, string semesterName, Semester* &curSemester, bool &semestercheck, char &sdefault)
{
	Semester* pCur = pSemester;
	if (pSemester == nullptr && semesterName.compare("1") != 0)
	{
		cout << "Semester 1 is not exist. Please create Semester 1 first.\n";
		return false;
	}
	else if (pSemester != nullptr && pSemester->semesterNext == nullptr && semesterName.compare("3") == 0)
	{
		cout << "Semester 2 is not exist. Please create Semester 2 first.\n";
		return false;
	}
	while (pCur != nullptr)
	{
		if (pCur->semesterName.compare(semesterName) == 0)
		{
			cout << "Failed to create a new semester!!\n";
			cout << "The semester you are about to create has already existed!!\n";
			system("pause");
			system("cls");
			return false;
		}
		pCur = pCur->semesterNext;
	}
	string dirO = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + yearName + "\\Semester\\";
	int check = _mkdir(dirO.c_str());
	dirO += "Semester " + semesterName;
	check = _mkdir(dirO.c_str());
	pCur = pSemester;
	if (pSemester == nullptr)
	{
		inputSemester(pSemester, semesterName, yearName);
		pSemester->semesterNext = nullptr;
		pCur = pSemester;
		do
		{
			cout << "Do you want to set this semester as your current semester? (y/n): ";
			cin >> sdefault;
			system("cls");

		} while (sdefault != 'y' && sdefault != 'n');
		if (sdefault == 'y')
		{
			curSemester = pCur;
			semestercheck = true;
		}
	}
	else
	{
		while (pCur->semesterNext != nullptr)
		{
			pCur = pCur->semesterNext;
		}
		inputSemester(pCur->semesterNext, semesterName,yearName);
		pCur = pCur->semesterNext;
		pCur->semesterNext = nullptr;
		do
		{
			cout << "Do you want to set this semester as your current semester? (y/n): ";
			cin >> sdefault;
			system("cls");

		} while (sdefault != 'y' && sdefault != 'n');
		if (sdefault == 'y')
		{
			curSemester = pCur;
			semestercheck = true;
		}
	}
	
	
	pCur = pSemester;
	fstream output;
	output.open("C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + yearName + "\\Semester\\Semester.txt", ios::out);
	while (pCur != nullptr)
	{
		cout << "\n";
		output << pCur->semesterName << "\n";
		output << pCur->startDate.day << " " << pCur->startDate.month << " " << pCur->startDate.year << "\n";
		output << pCur->endDate.day << " " << pCur->endDate.month << " " << pCur->endDate.year << "\n";
		output << pCur->startReg.day << " " << pCur->startReg.month << " " << pCur->startReg.year << "\n";
		output << pCur->endReg.day << " " << pCur->endReg.month << " " << pCur->endReg.year << "\n";
		pCur = pCur->semesterNext;
	}
	return true;
}
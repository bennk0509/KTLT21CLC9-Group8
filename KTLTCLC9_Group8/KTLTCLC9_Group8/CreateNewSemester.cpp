#include <iostream>
#include <fstream>
#include "Struct.h"

using namespace std;


void inputSemester(Semester* pSemester)
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
}


bool CreateNewSemester(Semester* pSemester, string yearName, string semesterName)
{
	Semester* pCur = pSemester;
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
	string dirO = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + yearName + "\\Semester\\" + "Semester " + semesterName;
	int check = _mkdir(dirO.c_str());
	if (pCur == nullptr)
	{
		inputSemester(pCur);
		pCur->semesterNext = nullptr;
		pCur = pCur->semesterNext;
	}
	
	pCur = pSemester;
	fstream output;
    output.open("C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + yearName + "\\Semester\\Semester.txt",ios::out);
	while (pCur != nullptr)
	{
		output << pCur->semesterName << endl;
		output << pCur->startDate.day << "-" << pCur->startDate.month << "-" << pCur->startDate.year << endl;
		output << pCur->endDate.day << "-" << pCur->endDate.month << "-" << pCur->endDate.year << endl;
	}
	return true;
}
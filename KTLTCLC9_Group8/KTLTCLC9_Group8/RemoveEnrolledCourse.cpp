#pragma warning(disable:4996)
#include "Struct.h"
#include "Student.h"
#include "System.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void removeEnrolledCourse(Course *&ELhead, string ID, Semester* pSemester, Student* &curStudent, string yearName)
{
	bool courseCheck = false;
	bool yearcheck = false;
	bool monthcheck = false;
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	if ((1900 + timePtr->tm_year) > pSemester->endReg.year || (1900 + timePtr->tm_year) < pSemester->startReg.year)
	{
		cout << "You cannot use this function at this moment. Please try again later.\n";
		return;
	}
	else
	{
		if ((timePtr->tm_mon + 1) > pSemester->endReg.month || (timePtr->tm_mon + 1) < pSemester->startReg.month)
		{
			cout << "You cannot use this function at this moment. Please try again later.\n";
			return;
		}
		else if (pSemester->endReg.month == pSemester->startReg.month)
		{
			if (timePtr->tm_mday > pSemester->endReg.day || timePtr->tm_mday < pSemester->startReg.day)
			{
				cout << "You cannot use this function at this moment. Please try again later.\n";
				return;
			}
		}
		else if (pSemester->endReg.month - pSemester->startReg.month == 1)
		{
			if ((timePtr->tm_mon + 1) == pSemester->startReg.month && timePtr->tm_mday < pSemester->startReg.day)
			{
				cout << "You cannot use this function at this moment. Please try again later.\n";
				return;
			}
			else if (timePtr->tm_mon + 1 == pSemester->endReg.month && timePtr->tm_mday > pSemester->endReg.day)
			{
				cout << "You cannot use this function at this moment. Please try again later.\n";
				return;
			}
		}
	}
    if(ELhead==nullptr) return;
    Course *cur=ELhead;
    if(ELhead->id==ID)
    {
        ELhead=ELhead->courseNext;
		int d1, d2, s1, s2;
		courseDate(d1, d2, s1, s2,ELhead);
		curStudent->coursesenrolled[s1][d1] = false;
		curStudent->coursesenrolled[s2][d2] = false;
        delete cur;
    }
    else
    {
        while(cur->courseNext!=nullptr && cur->courseNext->id!=ID)
        {
            cur=cur->courseNext;
        }
        if(cur->courseNext==nullptr)
        {
            cout<<"Course not found!";
            return;
        }
        Course *temp=cur->courseNext;
		int d1, d2, s1, s2;
		courseDate(d1, d2, s1, s2, temp);
		curStudent->coursesenrolled[s1][d1] = false;
		curStudent->coursesenrolled[s2][d2] = false;
        cur->courseNext=temp->courseNext;
        delete temp;
    }
	string dirO = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + yearName + "\\" + curStudent->classname + "\\" + curStudent->ID + ".txt";
	fstream fout;
	fout.open(dirO.c_str(), ios::out);
	Course * curEC = curStudent->EnrolledCourses;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 7; j++)
			fout << curStudent->coursesenrolled[i][j] << " ";
	fout << "\n";
	while (curEC != nullptr)
	{
		fout << curEC->id << endl;
		fout << curEC->name << endl;
		fout << curEC->lecturerName << endl;
		fout << curEC->sSemester << endl;
		fout << curEC->numberOfCredits << endl;
		fout << curEC->maxStudent << endl;
		fout << curEC->curStudentNum << endl;
		fout << curEC->date.d1 << " " << curEC->date.d2 << " " << curEC->date.s1 << " " << curEC->date.s2 << endl;
		curEC = curEC->courseNext;
	}
    system("cls");
    cout<<"Course Removed!";

}
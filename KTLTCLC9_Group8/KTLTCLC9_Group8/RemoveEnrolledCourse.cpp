#pragma warning(disable:4996)
#include "Struct.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void removeEnrolledCourse(Course *&ELhead, string ID, Semester* pSemester)
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
        cur->courseNext=temp->courseNext;
        delete temp;
    }
    system("cls");
    cout<<"Course Removed!";
}
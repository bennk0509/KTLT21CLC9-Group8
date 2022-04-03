#include "Struct.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void removeEnrolledCourse(Course *&ELhead, string ID, Semester* pSemester)
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    if (timePtr->tm_year > pSemester->endReg.year || timePtr->tm_year < pSemester->startReg.year)
    {
        cout << "You cannot enroll at this moment. Please try again later.\n";
        return;
    }
    if (timePtr->tm_mon > pSemester->endReg.month || timePtr->tm_mon < pSemester->startReg.month)
    {
        cout << "You cannot enroll at this moment. Please try again later.\n";
        return;
    }
    if (timePtr->tm_mday > pSemester->endReg.day || timePtr->tm_mday < pSemester->startReg.day)
    {
        cout << "You cannot enroll at this moment. Please try again later.\n";
        return;
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
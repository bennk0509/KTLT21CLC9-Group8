#include <iostream>
#include <fstream>
#include <string.h>
#include "Course.h"
#include "Struct.h"

using namespace std;

void ViewListCourse(Course *pCourse)
{
    Course *pCur=pCourse;
    while(pCur!=nullptr)
    {
        cout << "Course ID: "<<pCur->id<<endl;
        cout << "Course Name: "<<pCur->name<<endl;
        cout << "Lecturer Name: "<<pCur->lecturerName<<endl;
        cout << "Max Student: " << pCur->maxStudent << endl;
        cout << "Number of Credit: "<<pCur->numberOfCredits<<endl;
        cout << "Occur in: " << pCur -> date.d1 << " " << pCur -> date.s1 << " and " << pCur -> date.d2 << " " << pCur -> date.s2 << '\n';
        int count=0;
        Student* SIC=pCur->pStudent;
        while(SIC!=nullptr){
            count++;
            SIC=SIC->studentNext;
        }
        cout << "Number of students registered: "<<count<<pCur->maxStudent<<endl;
        pCur=pCur->courseNext;
    }
    system("pause");
    system("cls");
}
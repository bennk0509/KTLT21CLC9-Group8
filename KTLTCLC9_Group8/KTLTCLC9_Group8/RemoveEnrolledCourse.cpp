#include "Struct.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

void removeEnrolledCourse(Course *&ELhead, string ID)
{
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
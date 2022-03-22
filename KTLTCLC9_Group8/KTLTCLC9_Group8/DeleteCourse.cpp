#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "Struct.h"
#include "Course.h"
using namespace std;

void deleteCourse(Course *&head, string ID)
{
    if(head==nullptr) return;
    Course *cur=head;
    if(head->id==ID)
    {
        head=head->courseNext;
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
    cout<<"Course deleted!";
    updateCourseData(head);
}
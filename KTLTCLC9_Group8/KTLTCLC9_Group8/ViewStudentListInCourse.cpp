#include <iostream>
#include <string>
#include <iomanip>
#include "Staff.h"
#include "Struct.h"
using namespace std;

void viewStudentListInCourse(Student *head)
{
    if(head==nullptr) 
    {
        cout<<"There is no student in this course!";
        return;
    }
    Student *cur=head;
    cout<<setw(12) << left << "ID";
    cout<<setw(24) << left << "Name";
    cout<<setw(12) << left << "Birthday";
    cout<<setw(10) << left << "Classname";
    cout<<setw(8) << left << "Gender";
    while(cur!=nullptr)
    {
        cout<<setw(12) << left << cur->ID;
        cout<<setw(24) << left << cur->name;
        cout<<cur->DOB.day<<"/"<<cur->DOB.month<<"/"<<cur->DOB.year<<"\t";
        cout<<setw(10) << left << cur->classname;
        if(cur->gender)
            cout<<setw(8) << left << "Female";
        else
            cout<<setw(8) << left << "Male";
        cout<<"\n";
        cur=cur->studentNext;
    }
}

#include <iostream>
#include <string>
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
    cout<<"ID\t\t";
    cout<<"Name\t\t\t\t";
    cout<<"Birthday\t";
    cout<<"Classname\t";
    cout<<"Gender\n";
    while(cur!=nullptr)
    {
        if(cur->ID.size()<8)
            cout<<cur->ID<<"\t\t";
        else if(cur->ID.size()<12)
            cout<<cur->ID<<"\t";

        if(cur->name.size()<8)
            cout<<cur->name<<"\t\t\t\t";
        else if(cur->name.size()<12)
            cout<<cur->name<<"\t\t\t";
        else if(cur->name.size()<16)
            cout<<cur->name<<"\t\t";
        else if(cur->name.size()<20)
            cout<<cur->name<<"\t\t";

        cout<<cur->DOB.day<<"/"<<cur->DOB.month<<"/"<<cur->DOB.year<<"\t";

        if(cur->classname.size()<8)
            cout<<cur->classname<<"\t\t";
        else if(cur->classname.size()<12)
            cout<<cur->classname<<"\t";
        
        if(cur->gender)
            cout<<"Male\t";
        else
            cout<<"Female\t";
        cout<<"\n";
        cur=cur->studentNext;
    }
}

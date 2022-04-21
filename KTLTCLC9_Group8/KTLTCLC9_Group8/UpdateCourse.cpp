#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "Struct.h"
#include "Course.h"
using namespace std;

void updateCourseData(Course *head, Year* curYear, Semester* &curSemester) //ham nay can dien file direction voi cach luu
{

    string courseDir="C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + curYear->YearName + "\\Semester\\" + curSemester->semesterName + "\\Course.txt";
    fstream output;
    output.open(courseDir, ios::out);
    if(output.fail()) 
    {
        cout<<"Course data file opening failed!";
        return;
    }

    Course *cur;
    for(cur=head; cur!=nullptr; cur=cur->courseNext)
    {
        output << cur->id << '\n';
        output << cur->name << '\n';
        output << cur->lecturerName << '\n';
        output << cur->sSemester << '\n';
        output << cur->numberOfCredits << '\n';
        output << cur->maxStudent << '\n';
        output << cur->curStudentNum << '\n';
        output << cur->date.d1 << '\n' << cur->date.d2 << '\n';
        output << cur->date.s1 << '\n' << cur->date.s2 << '\n';
    }
    output.close();
}

void updateCourse(Course *head, string ID, Year* curYear, Semester*& curSemester)
{
    if(head==nullptr) return;
    Course *cur=head;
    while(cur!=nullptr)
    {
        if (cur->id.compare(ID) == 0)
            break;
        cur=cur->courseNext;
    }
    if(cur==nullptr)
    {
        cout<<"Course not found!";
        return;
    }

    bool cont=true;
    while(cont)
    {
        system("cls");
        int choose=0;
        cout<<"Choose information needing update:";
        cout<<"\n1. Course ID: "<<cur->id;
        cout<<"\n2. Course name: "<<cur->name;
        cout<<"\n3. Course lecturer: "<<cur->lecturerName;
        cout<<"\n4. Course semmester: "<<cur->sSemester;
        cout<<"\n5. Course credits: "<<cur->numberOfCredits;
        cout<<"\n6. Course limit: "<<cur->maxStudent;
        cout<<"\n7. Course time: "<<"\n\t+ "<<cur->date.s1<<" on "<<cur->date.d1<<"\n\t+ "<<cur->date.s2<<" on "<<cur->date.d2;
        cout<<"\n";
        do
        {
            cin>>choose;
        } while(choose<1 || choose >7);
        system("cls");
        switch(choose)
        {
            case 1:
                cout<<"Enter new course ID: ";
                cin>>cur->id;
                break;
            case 2:
                cout<<"Enter new course name: ";
                cin.ignore(1000, '\n');
                getline(cin, cur->name);
                break;
            case 3:
                cout<<"Enter new course lecturer's name: ";
                cin.ignore(1000, '\n');
                getline(cin, cur->lecturerName);
                break;
            case 4:
                cout<<"Enter new course semester: ";
                cin>>cur->sSemester;
                break;
            case 5:
                cout<<"Enter new number of credits: ";
                cin>>cur->numberOfCredits;
                break;
            case 6:
                cout<<"Enter new course limit: ";
                cin>>cur->maxStudent;
                break;
            case 7:
                cout<<"Enter new course time: ";
                cout<<"\n\tFor first shift: ";
                cout<<"\n\t\tDay: ";
                cin>>cur->date.d1;
                cout<<"\n\t\tShift: ";
                cin>>cur->date.s1;
                cout<<"\n\tFor second shift: ";
                cout<<"\n\t\tDay: ";
                cin>>cur->date.d2;
                cout<<"\n\t\tShift: ";
                cin>>cur->date.s2;
                break;
        }
        system("cls");
        cout<<"Course updated!";
        do
        {
            cout<<"\nPress 0 to exit, 1 to continue adjusting\n";
            cin>>choose;
        } while (choose!=0 && choose!=1);
        cont = (choose==1) ? true : false; 
    }
    updateCourseData(head,curYear,curSemester);
}

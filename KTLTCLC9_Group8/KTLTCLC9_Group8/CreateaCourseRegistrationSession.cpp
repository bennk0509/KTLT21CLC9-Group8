#include <iostream>
#include <fstream>
#include <string.h>
#include "Course.h"
#include "Struct.h"

using namespace std;


void CreateCourseRegistrationSession(Semester *&pSemester, string yearName)
{
    if(pSemester->startReg.year != - 1)
    {
        while(true)
        {
            cout << "There's already a course registration session in this semester."<<endl;
            cout << "This course from: "<<pSemester->startReg.day<<'/'<<pSemester->startReg.month<<'/'<<pSemester->startReg.year<<"to"<<pSemester->endReg.day<<'/'<<pSemester->endReg.month<<'/'<<pSemester->endReg.year<<endl;
            cout << "Try again if you want? "<<endl;
            cout << "1: Yes"<<endl;
            cout << "0: No"<<endl;
            cout <<"Your input here: ";
            char *input = new char[101];
            cin >>input;
            system("cls");
            if(strlen(input)>1 || (input[0] <'0' || input[0] >'1'))
            {
                cout <<"Invalid, Please try again"<<endl;
                continue;
            }
            system("cls");
            int x=input[0]-'0';
            delete[] input;
            if(x==0) return;
            else break;
        }
    }
    cout << ">>>>Please input start date of the registration session<<<<"<<endl;
    cout << "Day: "; cin >>pSemester->startReg.day;
    cout << "Month: "; cin >>pSemester->startReg.month;
    cout << "Year: "; cin >>pSemester->startReg.year;
    cout << ">>>>Please input end date of the registration session<<<<"<<endl;
    cout << "Day: "; cin >>pSemester->endReg.day;
    cout << "Month: "; cin >>pSemester->endReg.month;
    cout << "Year: "; cin >>pSemester->endReg.year;
    system("pause");
    system("cls");

    string dir = "C:\\KTLTCLC9_Group8\\Data\\yearName\\" + yearName + "\\Semester\\Semester.txt";
    ofstream fout(dir);
    Semester* curSemester = pSemester;
    while (curSemester != nullptr)
    {
        fout << curSemester->startDate.day << " " << curSemester->startDate.month << " " << curSemester->startDate.year << endl;
        fout << curSemester->endDate.day << " " << curSemester->endDate.month << " " << curSemester->endDate.year << endl;
        fout << curSemester->startReg.day << " " << curSemester->startReg.month << " " << curSemester->startReg.year << endl;
        fout << curSemester->endReg.day << " " << curSemester->endReg.month << " " << curSemester->endReg.year << endl;
        curSemester = curSemester->semesterNext;
    }
    cout << "Create new registration session successfully.\n";
}
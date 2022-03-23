#include <iostream>
#include <fstream>
#include <string.h>
#include "Course.h"
#include "Struct.h"

using namespace std;


void CreateACourseRegistrationSession(Semester *pSemester,string SemesterName)
{
    if(pSemester->startDate.year!=1)
    {
        while(true)
        {
            cout << "There's already a course registration session in this semester."<<endl;
            cout << "This course from: "<<pSemester->startDate.day<<'/'<<pSemester->startDate.month<<'/'<<pSemester->startDate.year<<"to"<<pSemester->endDate.day<<'/'<<pSemester->endDate.month<<'/'<<pSemester->endDate.year<<endl;
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
    cout << "Day: "; cin >>pSemester->startDate.day;
    cout << "Month: "; cin >>pSemester->startDate.month;
    cout << "Year: "; cin >>pSemester->startDate.year;
    cout << ">>>>Please input end date of the registration session<<<<"<<endl;
    cout << "Day: "; cin >>pSemester->endDate.day;
    cout << "Month: "; cin >>pSemester->endDate.month;
    cout << "Year: "; cin >>pSemester->endDate.year;
    system("pause");
    system("cls");
}
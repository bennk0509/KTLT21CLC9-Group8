#include "Struct.h"
#include "Staff.h"
#include <iostream>
#include <string>
using namespace std;

void viewClassesList(Year *pYear)
{
    Year *curYear=pYear;
    while(curYear!= nullptr)
    {
        Class *curClass = curYear->pClass;
        cout<<"Year "<<curYear->YearName;
        while(curClass!= nullptr)
        {
            cout<<"\t+ "<<curClass->className<<"\n";
        }
        curYear=curYear->yearNext;
    }
}
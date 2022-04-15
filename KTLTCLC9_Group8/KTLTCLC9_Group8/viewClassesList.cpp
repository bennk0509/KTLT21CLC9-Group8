#include "Struct.h"
#include "Staff.h"
#include <iostream>
#include <string>
using namespace std;

void viewClassesList(Year *pYear)
{
    Class *curClass = pYear->pClass;
    cout<<"Year "<<pYear->YearName;
    cout << "\n";
    while(curClass!= nullptr)
    {
        cout<<"\t" <<curClass->className<<"\n";
        curClass = curClass->classNext;
    }
    system("pause");
}
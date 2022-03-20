#include <iostream>
#include <fstream>
#include <string.h>
#include "Struct.h"
using namespace std;

void CreateNewYear(Year *&pYear, string yearname)
{
    Year *pCur=pYear;
    while(pCur!=nullptr)
    {
        if(pCur->YearName.compare(yearname) == 0) {
            cout << "Failed to create a new year!"<<endl;
            cout << "The year has already existed!"<<endl;
            return;
        }
        pCur=pCur->yearNext;
    }
    fstream output;
    output.open("Year.txt",ios::out);
    pCur=pYear;
    if(pYear==nullptr)
    {
        pYear=new Year;
        pYear->YearName=yearname;
        output << pYear->YearName<<endl;
    }
    else{
        while(pCur->yearNext!=nullptr)
        {
            output << pCur->YearName<<endl;
            pCur=pCur->yearNext;
        }
        output << pCur->YearName<<endl;
        pCur->yearNext=new Year;
        pCur=pCur->yearNext;
        pCur->YearName=yearname;
        output << pCur->YearName;
    }
    output.close();
}
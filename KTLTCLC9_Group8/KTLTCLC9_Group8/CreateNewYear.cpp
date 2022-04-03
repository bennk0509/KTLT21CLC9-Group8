#include <iostream>
#include <fstream>
#include <string.h>
#include "Struct.h"
#include <Windows.h>
#include <direct.h>

using namespace std;

void CreateNewYear(Year *&pYear, string yearname, int k)
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
    _mkdir("C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\yearname\\");
    string dirO("C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\yearname\\" + yearname);
    int check = _mkdir(dirO.c_str());
    fstream output;
    output.open("C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\yearname\\Year.txt",ios::out);
    pCur=pYear;
    if(pYear==nullptr)
    {
        pYear=new Year;
        pYear->YearName=yearname;
        output << pYear->YearName<<endl;
    }
    if (pYear == nullptr) {
        pYear = new Year;
        pYear->YearName = yearname;
        if (k)
            output << pYear->YearName;
    }
    else {
        while (pCur->yearNext != nullptr) {
            if (k)
                output << pCur->YearName << '\n';
            pCur = pCur->yearNext;
        }
        if (k)
            output << pCur->YearName << '\n';
        pCur->yearNext = new Year;
        pCur = pCur->yearNext;
        pCur->YearName = yearname;
        if (k)
            output << pCur->YearName;
    }
    if (k)
        output.close();
    output.close();
    cout << "Create new year successfully\n";
}
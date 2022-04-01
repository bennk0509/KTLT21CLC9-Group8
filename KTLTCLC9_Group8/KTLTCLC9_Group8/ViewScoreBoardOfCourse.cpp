#include <iostream>
#include <iomanip>
#include "Staff.h"
using namespace std;

void ViewScoreBoardOfCourse(Course *pCourse,string courseID)
{
    Scoreboard *pCur;
    pCur=pCourse->pScoreboard;
    cout << setw(60)<<right<<"VIEW THE SCOREBOARD"<<endl;
    cout << endl;
    cout <<setw(15)<<left<<"Name";
    cout <<setw(15)<<left<<"ID";
    cout <<setw(20)<<left<<"Midterm's Mark";
    cout <<setw(20)<<left<<"Final's Mark";
    cout <<setw(20)<<left<<"Bonus's Mark";
    cout <<setw(20)<<left<<"Total's Mark"<<endl;
    cout << endl;
    while (pCur!=nullptr) {
        cout << setw(15) << left << pCur->stu->name;
        cout << setw(15) << left << pCur->stu->ID;
        cout << setw(20) << left << pCur->midterm;
        cout << setw(20) << left << pCur->final;
        cout << setw(20) << left << pCur->bonus;
        cout << setw(20) << left << pCur->total << '\n';
        pCur = pCur->scoreboardNext;
    }
}
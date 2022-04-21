#include <iostream>
#include <iomanip>
#include "Staff.h"
using namespace std;

void ViewScoreBoardOfCourse(Course *pCourse,string courseID)
{
    Course* curCourse = pCourse;
    while (curCourse != nullptr)
    {
        if (curCourse->id.compare(courseID) == 0)
            break;
        curCourse = curCourse->courseNext;
    }
    if (curCourse == nullptr)
    {
        cout << "This course ID does not exist.\n";
        return;
    }
    Scoreboard *pCur;
    pCur=pCourse->pScoreboard;
    cout << setw(60)<<right<<"VIEW THE SCOREBOARD OF COURSE"<<endl;
    cout << endl;
    cout <<setw(15)<<left<< setw(30) << right <<"Name | ";
    cout <<setw(15)<<left<<"ID";
    cout <<setw(20)<<left<<"Midterm's Mark";
    cout <<setw(20)<<left<<"Final's Mark";
    cout <<setw(20)<<left<<"Bonus's Mark";
    cout <<setw(20)<<left<<"Total's Mark"<<endl;
    cout << endl;
    while (pCur!=nullptr) {
        cout << setw(15) << left << setw(30) << right << pCur->stu->name << " | ";
        cout << setw(15) << left << pCur->stu->ID;
        cout << setw(20) << left << pCur->midterm;
        cout << setw(20) << left << pCur->final;
        cout << setw(20) << left << pCur->bonus;
        cout << setw(20) << left << pCur->total << '\n';
        pCur = pCur->scoreboardNext;
    }
}
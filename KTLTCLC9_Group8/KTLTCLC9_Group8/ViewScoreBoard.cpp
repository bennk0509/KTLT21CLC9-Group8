#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Student.h"

void ViewScoreBoard(Course *pCourse, string studentID)
{
    Scoreboard *pCur;
    cout << setw(60)<<right<<"VIEW THE SCOREBOARD"<<endl;
    cout << endl;
    cout <<setw(15)<<left<<"Course";
    cout <<setw(20)<<left<<"Midterm's Mark";
    cout <<setw(20)<<left<<"Final's Mark";
    cout <<setw(20)<<left<<"Bonus's Mark";
    cout <<setw(20)<<left<<"Total's Mark"<<endl;
    cout << endl;
    while(pCourse!=nullptr)
    {
        for(pCur=pCourse->pScoreboard;pCur!=nullptr;pCur=pCur->scoreboardNext)
        {
            if (pCur->stu->ID.compare(studentID) == 0)
            {
                cout << setw(15) << left << pCourse->id;
                cout << setw(20) << left << pCur->midterm;
                cout << setw(20) << left << pCur->final;
                cout << setw(20) << left << pCur->bonus;
                cout << setw(20) << left << pCur->total << endl;
                cout << endl;
                break;
            }
        }
    pCourse=pCourse->courseNext;
    }
    system("pause");
    system("cls");
}
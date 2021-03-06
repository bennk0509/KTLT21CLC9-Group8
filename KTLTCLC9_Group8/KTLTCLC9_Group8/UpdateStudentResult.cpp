#include <iostream>
#include <fstream>
#include <string>
#include "Staff.h"

void UpdateStudentResult(Scoreboard* &pScoreboard, string studentID)
{
    Scoreboard*pCur=pScoreboard;
    while(pCur!=nullptr && pCur->stu->ID.compare(studentID) != 0) pCur=pCur->scoreboardNext;
    if (pCur != nullptr)
    {
        cout << "Update Score of student " << studentID << endl;
        cout << "Midterm's mark: "; cin >> pCur->midterm;
        cout << "Final's mark: "; cin >> pCur->final;
        cout << "Bonus's mark: "; cin >> pCur->bonus;
        cout << "Total's mark: "; cin >> pCur->total;
        cout << "Scoreboard of student " << studentID << " has updated" << endl;
    }
    else
        cout << "This student ID does not exist.\n";
    system("pause");
    system("cls");
}
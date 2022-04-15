#include "Struct.h"
#include "Staff.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void importScoreboard(string courseID, Year* curYear, Semester* &curSemester)
{
    string scoreboardDir="";
    cout << "Input file's directorty (example: C:\\\\data\\\\student.csv)\n";
    cout << ">>>>";
    cin >> scoreboardDir;
    fstream scoreboardcsv;
    scoreboardcsv.open(scoreboardDir,ios::in);
    if (!scoreboardcsv)
    {
        cout << "Cannot open file.\n";
        return;
    }
    Course *curCourse=curSemester->pCourse;
    while(curCourse->id!=courseID) //go to course with course id
        curCourse=curCourse->courseNext;
    Scoreboard *curSB = curCourse->pScoreboard;
    string temp;
    // No, Student ID, Student Full Name, Total Mark, Final Mark, Midterm Mark, Other Mark. 
    while(!scoreboardcsv.eof()) //get data line by line
    {
        scoreboardcsv.ignore(1000,'\n');
        Scoreboard *newSB= new Scoreboard;
        getline(scoreboardcsv,temp,',');
        getline(scoreboardcsv,temp,',');
        if(findStudent(curYear,temp)==nullptr) //if studnent id doesnt exist, skip that info
        {
            getline(scoreboardcsv,temp,'\n');
            continue;
        }
        newSB->stu=findStudent(curYear,temp);
        getline(scoreboardcsv,temp,',');
        getline(scoreboardcsv,temp,',');
        newSB->total=stof(temp);
        getline(scoreboardcsv,temp,',');
        newSB->final=stof(temp);
        getline(scoreboardcsv,temp,',');
        newSB->midterm=stof(temp);
        getline(scoreboardcsv,temp,'\n');
        newSB->bonus=stof(temp);
        curSB->scoreboardNext=newSB;
        curSB=curSB->scoreboardNext;
    }
}

Student *findStudent(Year* curYear, string stuID) //find student with student id in curYear
{
    Student *curStu;
    Class *curClass=curYear->pClass;
    while(curClass!=nullptr)
    {
        curStu=curClass->pStudent;
        while (curStu != nullptr)
        {
            if (curStu->ID.compare(stuID) == 0)
                break;
            curStu = curStu->studentNext;
        }
            
        if(curStu!=nullptr)
            return curStu;
        else
            curClass=curClass->classNext;
    }
    return nullptr;
}

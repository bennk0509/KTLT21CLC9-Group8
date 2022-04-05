#include "Struct.h"
#include "Staff.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void importScoreboard(string courseID, Year* curYear, Semester* &curSemester)
{
    string scoreboardDir="";
    fstream scoreboardcsv;
    scoreboardcsv.open(scoreboardDir,ios::in);
    Course *curCourse=curSemester->pCourse;
    while(curCourse->id!=courseID)
        curCourse=curCourse->courseNext;
    Scoreboard *curSB = curCourse->pScoreboard;
    string temp;
    // No, Student ID, Student Full Name, Total Mark, Final Mark, Midterm Mark, Other Mark. 
    while(!scoreboardcsv.eof())
    {
        scoreboardcsv.ignore(1000,'\n');
        Scoreboard *newSB= new Scoreboard;
        getline(scoreboardcsv,temp,',');
        getline(scoreboardcsv,temp,',');
        if(findStudent(curYear,temp)==nullptr) 
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

Student *findStudent(Year* curYear, string stuID)
{
    Student *curStu;
    Class *curClass=curYear->pClass;
    while(curClass!=nullptr)
    {
        curStu=curClass->pStudent;
        while(curStu->ID!=stuID && curStu!=nullptr)
            curStu=curStu->studentNext;
        if(curStu!=nullptr)
            return curStu;
        else
            curClass=curClass->classNext;
    }
    return nullptr;
}
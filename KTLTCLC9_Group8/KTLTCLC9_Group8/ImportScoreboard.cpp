#include "Struct.h"
#include "Staff.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void importScoreboard(string courseID, Year* curYear, Semester* &curSemester,int mode)
{
    
    Course *curCourse=curSemester->pCourse;
    while(curCourse != nullptr) //go to course with course id
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
    string scoreboardDir = "";
    cout << "Input file's directorty (example: C:\\\\data\\\\student.csv)\n";
    cout << ">>>>";
    cin.ignore(1000, '\n');
    getline(cin, scoreboardDir);
    fstream scoreboardcsv;
    scoreboardcsv.open(scoreboardDir, ios::in);
    if (!scoreboardcsv)
    {
        cout << "Cannot open file.\n";
        return;
    }
    Scoreboard *curSB = curCourse->pScoreboard;
    string temp;
    ofstream fout;
    string dirO = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + curYear->YearName + "\\Semester" + "\\" + curSemester->semesterName + "\\" + curCourse->id + "\\Scoreboard.txt";
    
    // No, Student ID, Student Full Name, Total Mark, Final Mark, Midterm Mark, Other Mark. 
    while(!scoreboardcsv.eof()) //get data line by line
    {
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
        if (curCourse->pScoreboard == nullptr)
        {
            curCourse->pScoreboard = newSB;
            curSB = curCourse->pScoreboard;
        }
        else
        {
            curSB->scoreboardNext = newSB;
            curSB = curSB->scoreboardNext;
        }
        
    }
    if (mode == 1)
    {
        fout.open(dirO);
        curSB = curCourse->pScoreboard;
        int count = 1;
        while (curSB != nullptr)
        {
            fout << count << "," << curSB->stu->ID << "," << curSB->stu->name << "," << curSB->total << "," << curSB->final << "," << curSB->midterm << "," << curSB->bonus << "\n";
            curSB = curSB->scoreboardNext;
            count++;
        }
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

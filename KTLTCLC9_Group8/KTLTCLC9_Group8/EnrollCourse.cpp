#pragma warning(disable:4996)
#include <iostream>
#include "Struct.h"
#include <ctime>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

void EnrollCourse(Course* &pCourse, Student* &curStudent, string CourseID, string yearName, Semester* pSemester)
{
	bool courseCheck = false;
	bool yearcheck = false;
	bool monthcheck = false;
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	if ((1900 + timePtr->tm_year) > pSemester->endReg.year || (1900 + timePtr->tm_year) < pSemester->startReg.year)
	{
		cout << "You cannot enroll at this moment. Please try again later.\n";
		return;
	}
	else
	{
		if ((timePtr->tm_mon + 1) > pSemester->endReg.month || (timePtr->tm_mon + 1) < pSemester->startReg.month)
		{
			cout << "You cannot enroll at this moment. Please try again later.\n";
			return;
		}
		else if (pSemester->endReg.month == pSemester->startReg.month)
		{
			if (timePtr->tm_mday > pSemester->endReg.day || timePtr->tm_mday < pSemester->startReg.day)
			{
				cout << "You cannot enroll at this moment. Please try again later.\n";
				return;
			}
		}
		else if (pSemester->endReg.month - pSemester->startReg.month == 1)
		{
			if ((timePtr->tm_mon + 1) == pSemester->startReg.month && timePtr->tm_mday < pSemester->startReg.day)
			{
				cout << "You cannot enroll at this moment. Please try again later.\n";
				return;
			}
			else if (timePtr->tm_mon + 1 == pSemester->endReg.month && timePtr->tm_mday > pSemester->endReg.day)
			{
				cout << "You cannot enroll at this moment. Please try again later.\n";
				return;
			}
		}
	}
	if (pCourse == nullptr)
		return;
	Course* curCourse = pCourse;
	while (curCourse != nullptr)
	{
		if (curCourse->id.compare(CourseID) == 0)
		{
			courseCheck = true;
			break;
		}
			
		curCourse = curCourse->courseNext;
	}
	if (!courseCheck)
	{
		cout << "This course ID does not exist.\n";
		return;
	}
	int d1, d2, s1, s2;
	if (curCourse->date.d1.compare("MON") == 0) d1 = 0;
	else if (curCourse->date.d1.compare("TUE") == 0) d1 = 1;
	else if (curCourse->date.d1.compare("WED") == 0) d1 = 2;
	else if (curCourse->date.d1.compare("THU") == 0) d1 = 3;
	else if (curCourse->date.d1.compare("FRI") == 0) d1 = 4;
	else if (curCourse->date.d1.compare("SAT") == 0) d1 = 5;
	else if (curCourse->date.d1.compare("SUN") == 0) d1 = 6;

	if (curCourse->date.d2.compare("MON") == 0) d2 = 0;
	else if (curCourse->date.d2.compare("TUE") == 0) d2 = 1;
	else if (curCourse->date.d2.compare("WED") == 0) d2 = 2;
	else if (curCourse->date.d2.compare("THU") == 0) d2 = 3;
	else if (curCourse->date.d2.compare("FRI") == 0) d2 = 4;
	else if (curCourse->date.d2.compare("SAT") == 0) d2 = 5;
	else if (curCourse->date.d2.compare("SUN") == 0) d2 = 6;

	if (curCourse->date.s1.compare("7:30") == 0) s1 = 0;
	else if (curCourse->date.s1.compare("9:30") == 0) s1 = 1;
	else if (curCourse->date.s1.compare("13:30") == 0) s1 = 2;
	else if (curCourse->date.s1.compare("15:30") == 0) s1 = 3;

	if (curCourse->date.s2.compare("7:30") == 0) s2 = 0;
	else if (curCourse->date.s2.compare("9:30") == 0) s2 = 1;
	else if (curCourse->date.s2.compare("13:30") == 0) s2 = 2;
	else if (curCourse->date.s2.compare("15:30") == 0) s2 = 3;


	
	if (curStudent->coursesenrolled[s1][d1] || curStudent->coursesenrolled[s2][d2])
	{
		cout << "The current course has sessions that are conflict with existing enrolled course sessions, cannot enroll!\n\n";
		return;
	}
	
	int count = 0;
	Course* curEC = curStudent ->EnrolledCourses;
	while (curEC != nullptr)
	{
		count++;
		curEC = curEC->courseNext;
	}
	if (count >= 5)
	{
		cout << "You have reached maximum courses, cannot enroll.\n";
		return;
	}
	if (curCourse->curStudentNum == curCourse->maxStudent)
	{
		cout << "Reached maximum students, cannot enroll.\n";
		return;
	}
	
	curStudent->coursesenrolled[s1][d1] = true;
	curStudent->coursesenrolled[s2][d2] = true;
	if (curStudent->EnrolledCourses == nullptr)
	{
		curStudent->EnrolledCourses = new Course;
		curStudent->EnrolledCourses->id = curCourse->id;
		curStudent->EnrolledCourses->name = curCourse->name;
		curStudent->EnrolledCourses->lecturerName = curCourse->lecturerName;
		curStudent->EnrolledCourses->sSemester = curCourse->sSemester;
		curStudent->EnrolledCourses->numberOfCredits = curCourse->numberOfCredits;
		curStudent->EnrolledCourses->maxStudent = curCourse->maxStudent;
		curStudent->EnrolledCourses->date.d1 = curCourse->date.d1;
		curStudent->EnrolledCourses->date.d2 = curCourse->date.d2;
		curStudent->EnrolledCourses->date.s1 = curCourse->date.s1;
		curStudent->EnrolledCourses->date.s2 = curCourse->date.s2;
		curStudent->EnrolledCourses->courseNext = nullptr;
		curEC = curStudent->EnrolledCourses;
	}
	else
	{
		curEC = curStudent->EnrolledCourses;
		while (curEC->courseNext != nullptr)
			curEC = curEC->courseNext;
		curEC->courseNext = new Course;
		curEC = curEC->courseNext;
		curEC->id = curCourse->id;
		curEC->name = curCourse->name;
		curEC->lecturerName = curCourse->lecturerName;
		curEC->sSemester = curCourse->sSemester;
		curEC->numberOfCredits = curCourse->numberOfCredits;
		curEC->maxStudent = curCourse->maxStudent;
		curEC->date.d1 = curCourse->date.d1;
		curEC->date.d2 = curCourse->date.d2;
		curEC->date.s1 = curCourse->date.s1;
		curEC->date.s2 = curCourse->date.s2;
		curEC->courseNext = nullptr;
	}
	curCourse->curStudentNum++;
	Student* stuCourse = curCourse->pStudent;
	if (curCourse->pStudent == nullptr)
	{
		curCourse->pStudent = new Student;
		stuCourse = curCourse->pStudent;
		stuCourse->classname = curStudent->classname;
		stuCourse->name = curStudent->name;
		stuCourse->ID = curStudent->ID;
		stuCourse->DOB = curStudent->DOB;
		stuCourse->studentNext = nullptr;
	}
	else
	{
		while (stuCourse->studentNext != nullptr)
			stuCourse = stuCourse->studentNext;
		stuCourse->studentNext = new Student;
		stuCourse = stuCourse->studentNext;
		stuCourse->classname = curStudent->classname;
		stuCourse->name = curStudent->name;
		stuCourse->ID = curStudent->ID;
		stuCourse->DOB = curStudent->DOB;
		stuCourse->studentNext = nullptr;
	}
	string dirO = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + yearName +"\\" + curStudent->classname + "\\" + curStudent->ID + ".txt";
	fstream fout;
	fout.open(dirO.c_str(), ios::out);
	curEC = curStudent->EnrolledCourses;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 7; j++)
			fout << curStudent->coursesenrolled[i][j] << " ";
	fout << "\n";
	int c = 0;
	while (curEC != nullptr)
	{
		if (c > 0)
			fout << endl;
		fout << curEC->id << endl;
		fout << curEC->name << endl;
		fout << curEC->lecturerName << endl;
		fout << curEC->sSemester << endl;
		fout << curEC->numberOfCredits << endl;
		fout << curEC->maxStudent << endl;
		fout << curEC->curStudentNum << endl;
		fout << curEC->date.d1 << " " << curEC->date.d2 << " " << curEC->date.s1 << " " << curEC->date.s2;
		c++;
		curEC = curEC->courseNext;
	}
}
#include <iostream>
#include "Struct.h"
using namespace std;

void EnrollCourse(Course* &pCourse, Student* &pStudent, string CourseID, string studentID, string yearName, string semesterName)
{
	Course* curCourse = pCourse;
	while (curCourse != nullptr)
	{
		if (curCourse->id.compare(CourseID) == 0)
			break;
		curCourse = curCourse->courseNext;
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

	if (curCourse->date.s1.compare("7.30") == 0) s1 = 0;
	else if (curCourse->date.s1.compare("9.30") == 0) s1 = 1;
	else if (curCourse->date.s1.compare("1.30") == 0) s1 = 2;
	else if (curCourse->date.s1.compare("3.30") == 0) s1 = 3;

	if (curCourse->date.s2.compare("7.30") == 0) s2 = 0;
	else if (curCourse->date.s2.compare("9.30") == 0) s2 = 1;
	else if (curCourse->date.s2.compare("1.30") == 0) s2 = 2;
	else if (curCourse->date.s2.compare("3.30") == 0) s2 = 3;


	Student* curStudent = pStudent;
	while (curStudent != nullptr)
	{
		if (curStudent->ID.compare(studentID) == 0)
		{
			if (curStudent->coursesenrolled[s1][d1] || curStudent->coursesenrolled[s2][d2])
			{
				cout << "The current course has sessions that are conflict with existing enrolled course sessions, cannot enrolled!\n\n";
				return;
			}
		}
	}
	int count = 0;
	Course* curEC = curStudent->EnrolledCourses;
	while (curEC != nullptr)
	{
		count++;
		curEC = curEC->courseNext;
	}
	if (count >= 5)
	{
		cout << "You have reached maximum courses, cannot enroll";
		return;
	}
	if (curCourse->curStudentNum == curCourse->maxStudent)
	{
		cout << "Reached maximum students, cannot enroll";
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
		while (curEC != nullptr)
			curEC = curEC->courseNext;
		curEC = new Course;
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
		while (stuCourse != nullptr)
			stuCourse = stuCourse->studentNext;
		stuCourse = new Student;
		stuCourse->classname = curStudent->classname;
		stuCourse->name = curStudent->name;
		stuCourse->ID = curStudent->ID;
		stuCourse->DOB = curStudent->DOB;
		stuCourse->studentNext = nullptr;
	}
	string dirO = "\\Data\\yearName\\" + yearName; +"\\" + curStudent->classname + "\\" + curStudent->ID + ".txt";
	fstream fout;
	fout.open(dirO.c_str(), ios::out);
	curEC = curStudent->EnrolledCourses;
	while (curEC != nullptr)
	{
		fout << curEC->id << endl;
		fout << curEC->name << endl;
		fout << curEC->lecturerName << endl;
		fout << curEC->sSemester << endl;
		fout << curEC->maxStudent << endl;
		fout << curEC->numberOfCredits << endl;
	}
}
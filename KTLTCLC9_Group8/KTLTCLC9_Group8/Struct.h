#ifndef _STRUCT_H
#define _STRUCT_H

#include <string>
#include <fstream>
#include <Windows.h>
#include <direct.h>
using namespace std;

struct dayPerformed {
	string d1; // day
	string d2;
	string s1; // shift
	string s2;
};
struct Date
{
	int day, month, year;
};

struct Student
{
	string ID;
	string name;
	Date DOB;
	string classname;
	int gender = 0;
	bool coursesenrolled[4][7] = {};
	Course* EnrolledCourses = nullptr;
	Student* studentNext = nullptr;
};

struct Class
{
	string yearName, className;
	Class* classNext=nullptr;
};

struct Semester
{
	Date startDate, endDate;
	string yearName;
	string semesterName;
	Semester* semesterNext=nullptr;
};

struct Year
{
	string YearName;
	Year* yearNext=nullptr;
	Class* pClass=nullptr;
	Semester* pSemester=nullptr;
};

struct Course {
	string id;
	string name;
	string lecturerName;
	string sSemester;
	int numberOfCredits;
	int maxStudent;
	int curStudentNum;
	dayPerformed date;
	Student* pStudent = nullptr;
	Course* courseNext = nullptr;
	Scoreboard* pScoreboard = nullptr;
};

struct Scoreboard {
	Student *stu=nullptr;
	float midterm;
	float final;
	float bonus;
	float total;
	Scoreboard *scoreboardNext = nullptr;
};
#endif // _STRUCT_H


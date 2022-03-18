﻿#ifndef _STRUCT_H
#define _STRUCT_H

#include <string>
using namespace std;


struct Date
{
	int day, month, year;
};

struct Student
{
	string ID;
	string name;
	Date BOD;
	string classname;
	int gender = 0;
	Student* studentNext;
};

struct Class
{
	string yearName, className;
	Class* cNext;
};

struct Semester
{
	//semester data


	Semester* semesterNext;
};

struct Year
{
	string YearName;
	Year* yearNext;
	Class* pClass;
	Semester* pSemester;
};
#endif // _STRUCT_H


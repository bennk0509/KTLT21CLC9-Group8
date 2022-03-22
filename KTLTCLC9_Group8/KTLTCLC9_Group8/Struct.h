#ifndef _STRUCT_H
#define _STRUCT_H

#include <string>
#include <Windows.h>
#include <direct.h>
using namespace std;


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
	Student* studentNext = nullptr;
};

struct Class
{
	string yearName, className;
	Class* classNext;
};

struct Semester
{
	Date startDate, endDate;
	string yearName;
	string semesterName;
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


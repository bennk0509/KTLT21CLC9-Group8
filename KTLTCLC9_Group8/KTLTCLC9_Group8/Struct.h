#ifndef _STRUCT_H
#define _STRUCT_H

#include <string>
using namespace std;


struct Date
{
	int date, month, year;
};

struct Student
{
	string ID;
	string name;
	Date birthday;
	string classname;
	int gender = 0;
	Student* sNext;
};

struct Class
{
	string yearName, className;
	Class* cNext;
};

struct Semester
{
	//semester data


	Semester* sNext;
};

struct Year
{
	char* YearName;
	Year* yearNext;
	Class* pClass;
	Semester* pSemester;
};
#endif // _STRUCT_H


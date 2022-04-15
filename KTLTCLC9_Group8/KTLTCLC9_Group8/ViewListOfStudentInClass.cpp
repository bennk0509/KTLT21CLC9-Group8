#include "Struct.h"
#include "Course.h"
#include "Staff.h"
#include <string.h>
#include <iomanip>
#include <iostream>

using namespace std;


void viewListOfStudentsInClass(Year* pYear, string className) {
	Class* curClass = pYear->pClass;
	while (curClass != nullptr)
	{
		if (curClass->className == className)
			break;
		curClass = curClass->classNext;
	}
	if (curClass == nullptr)
	{
		cout << "This class does not exist.\n";
		return;
	}
	Student* curStu = curClass->pStudent;
	while (curStu != nullptr)
	{
		cout << curStu->ID << "  " << curStu->name << "  " <<  curStu->DOB.day << "/" << curStu->DOB.month << "/" << curStu->DOB.year << "  " << curStu->gender << endl;
		curStu = curStu->studentNext;
	}

	
}



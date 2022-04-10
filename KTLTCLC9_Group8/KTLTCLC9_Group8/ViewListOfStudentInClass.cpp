#include "Struct.h"
#include "Course.h"
#include "Staff.h"
#include <string.h>
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
		cout << curStu->ID << endl;
		curStu = curStu->studentNext;
	}

	
}



#include "Struct.h"
#include "Course.h"
#include "Staff.h"
#include <string.h>
#include <iostream>

using namespace std;


void viewListOfStudentsInClass(Year* pYear, string className) {
	Class* curClass = pYear->pClass;
	if (curClass == nullptr)
	{
		cout << "This class is not exist.\n";
		return;
	}
		
	while (curClass->className.compare(className) != 0)
	{
		curClass = curClass->classNext;
	}

	Student* curStu = curClass->pStudent;
	while (curStu != nullptr)
	{
		cout << curStu->ID << endl;
		curStu = curStu->studentNext;
	}

	
}



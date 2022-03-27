#include "Header.h"
#include "Course.h"
#include "Staff.h"
#include <string.h>
#include <iostream>

using namespace std;


void viewListOfStudentsInClass(Year* pYear, string className) {
	while (pYear) {
		while (pYear->pClass) {
			if (strcmp(pYear->pClass->ClassName, className) == 0) {
				while (pYear->pClass->pStudent) {
					viewStudentInfo(pYear->pClass->pStudent);
					pYear->pClass->pStudent = pYear->pClass->pStudent->studentNext;
				}
				return;
			}
			pYear->pClass = pYear->pClass->classNext;
		}
		pYear = pYear->yearNext;
	}
}



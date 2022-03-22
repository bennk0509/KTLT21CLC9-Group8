#include <iostream>
#include <fstream>
#include "string.h"
#include "Course.h"
#include "Header.h"

using namespace std;

void addNewCourse(Course*& pCourse, string semesterName, string yearName, Course *& newCourse, int add) {
   	Course * pCur = pCourse;
   	while (pCur != nullptr) {
   		if (strcmp(pCur -> id, newCourse -> id) == 0) {
			cout << "Failed to add a new course!!\n";
			cout << "The course you are about to add has already existed!!\n";
			system("pause");
			system("cls");
			return;
   		}
   		pCur = pCur -> courseNext;
   	}
    char dirD[] = "C:\Data\YearName\Semester\SemesterName\\";
    string c = "";
    strcat(c, dirD);
    strcat(c, yearName);
    strcat(c, "\\Semester\\");
    strcat(c, semesterName);

	char mkdir[505] = "mkdir ";
	strcat(mkdir, c);
	strcat(mkdir, "\\");
	strcat(mkdir, newCourse -> id);
	system(mkdir);

    strcat(c, "\\Course.txt");

    ofstream fout;

    if (add == 1)
	    fout.open(c);

   	pCur = pCourse;

    if (!pCourse) {
        pCourse = newCourse;
        pCur = pCourse;
    }
    else {
        while (pCur -> courseNext) {
            pCur = pCur -> courseNext;
        }
        pCur -> courseNext = newCourse;
        pCur = pCur -> courseNext;
    }

    if (add == 1) {
    	pCur = pCourse;
    	while (pCur != nullptr) {
	        fout << pCur -> id << '\n';
	        fout << pCur -> name << '\n';
	        fout << pCur -> lecturerName << '\n';
	        fout << pCur -> numberOfCredits << '\n';
	        fout << pCur -> maxStudent << '\n';
	        fout << pCur -> date.d1 << '\n' << pCur->date.s1 << '\n';
	        fout << pCur -> date.d2 << '\n' << pCur->date.s2 << '\n';
	        pCur = pCur -> courseNext;
	    }
 	}

    if (add == 1)
	    fout.close();
}

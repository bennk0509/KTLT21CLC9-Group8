#include "Staff.h"
#include "Header.h"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

void viewScoreBoardOfClass(Student * pStudent, Semester * pSemester) {
	char * semesterName = new char[11];
	while (1) {
		cout << "Please input the name of the semester you want to see the scoreboard: ";
		cin >> semesterName;
		if (strlen(semesterName) > 1 || semesterName[0] < '0' || '3' < semesterName[0]) {
			system("cls");
			cout << "Invalid, please try again\n\n";
			continue;
		}
		break;
	}
	system("cls");
    cout << setw(18) << left << "Student's ID";
    cout << setw(30) << left << "Student's Name";

    Semester *curSem = pSemester;
    while (curSem) {
    	if (strcmp(curSem -> SemesterName, semesterName) == 0) {
    		Course *curCourse = curSem -> pCourse;
    		while (curCourse) {
    			cout << setw(10) << left << curCourse -> id;
    			curCourse = curCourse -> courseNext;
    		}
    	}
    	curSem = curSem -> semesterNext;
    }

    cout << setw(20) << left << "GPA this semester";
    cout << setw(20) << left << "GPA overall" << '\n';
    cout << '\n';

    Student *curStu = pStudent;
	while (curStu) {
	    cout << setw(18) << left << curStu -> studentID;
	    cout << setw(30) << left << curStu -> Name; 
		curSem = pSemester;
			
		int cntCourseSem = 0;
		double totMarkSem = 0;
		int cntCourse = 0;
		double totCourse = 0;

		while (curSem) {
	    	Course *curCourse = curSem -> pCourse;
	    	while (curCourse) {
	    		Scoreboard *curScr = curCourse -> pScoreboard;
	    		while (curScr) {
	    			if (strcmp(curScr -> stu -> studentID, curStu -> studentID) == 0) { 
						if (strcmp(curSem -> SemesterName, semesterName) == 0) {
			    			cout << setw(10) << left << curScr -> total;
			    			cntCourseSem++;
			    			totMarkSem += curScr -> total;
						}
						cntCourse++;
						totCourse += curScr -> total;
					}
					curScr = curScr -> scoreboardNext;
				}
			    curCourse = curCourse -> courseNext;
	    	}
	    	curSem = curSem -> semesterNext;
		}

  	  	cout << setw(20) << left << totMarkSem / cntCourseSem;
	    cout << setw(20) << left << totCourse / cntCourse << '\n';

		curStu = curStu -> studentNext;
	}

	system("pause");
	system("cls");
 	delete[] semesterName;
}
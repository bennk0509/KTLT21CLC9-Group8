#include <iostream>
#include <string.h>
#include "Header.h"
#include "Student.h"

using namespace std;

void viewEnrollList(Course* pEnrollCourse, string semesterName){
	Course * pCur = pEnrollCourse;
	while(pCur != nullptr){
		if (strcmp(semesterName, pCur -> sSemester) == 0) {
		    cout << "Course ID: " << pCur -> id << '\n';
		    cout << "Course Name: " << pCur -> name << '\n';
		    cout << "Lecturer Name: " << pCur -> lecturerName << '\n';
			cout << "Number of Credit: " << pCur -> numberOfCredits << '\n';
		    cout << "Occur in: " << pCur -> date.d1 << " " << pCur -> date.s1 << " and " << pCur -> date.d2 << " " << pCur -> date.s2 << '\n';
			cout << '\n';        
		}	
		pCur = pCur -> courseNext;
	}
}

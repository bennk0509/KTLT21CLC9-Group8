#include <iostream>
#include <fstream>
#include "string.h"
#include "Course.h"
#include "Struct.h"

using namespace std;

void addNewCourse(Course*& pCourse, string semesterName, string yearName, Course *& newCourse, int add) {
   	Course * pCur = pCourse;
   	while (pCur != nullptr) {
   		if (pCur->id.compare(newCourse->id) == 0) {
			cout << "Failed to add a new course!!\n";
			cout << "The course you are about to add has already existed!!\n";
			system("pause");
			system("cls");
			return;
   		}
   		pCur = pCur -> courseNext;
   	}
    string dirD = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\";
    string c = dirD + yearName + "\\Semester\\" + semesterName;
 

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
    if (add == 1)
        _mkdir((c + "\\" + newCourse->id).c_str());
    c += "\\Course.txt";
    ofstream fout;
    if (add == 1)
        fout.open(c);
    if (add == 1) {
    	pCur = pCourse;
    	while (pCur != nullptr) {
	        fout << pCur -> id << '\n';
	        fout << pCur -> name << '\n';
	        fout << pCur -> lecturerName << '\n';
            fout << pCur->sSemester << '\n';
	        fout << pCur -> numberOfCredits << '\n';
	        fout << pCur -> maxStudent << '\n';
            fout << pCur->curStudentNum << '\n';
	        fout << pCur -> date.d1 << '\n' << pCur->date.d2 << '\n';
	        fout << pCur -> date.s1 << '\n' << pCur->date.s2 << '\n';
	        pCur = pCur -> courseNext;
	    }
 	}

    if (add == 1)
        fout.close();
  	   
}

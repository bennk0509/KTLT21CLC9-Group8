#ifndef _COURSE_H
#define _COURSE_H
#include "Struct.h"

void inputSemester(Semester*& pSemester, string semesterName, string yearName);
bool CreateNewSemester(Semester* &pSemester, string yearName, string semesterName, Semester*& curSemester, bool& semestercheck, char& sdefault);
void addNewCourse(Course*& pCourse, string semesterName, string yearName, Course*& newCourse, int add);
void updateCourseData(Course* head, Year* curYear, Semester*& curSemester);
void updateCourse(Course* head, string ID, Year* curYear, Semester*& curSemester);
void deleteCourse(Course*& head, string ID, Year* curYear, Semester*& curSemester);
void CreateCourseRegistrationSession(Semester *&pSemester,string yearName);
void ViewListCourse(Course* pCourse);
#endif // ! _COURSE_H

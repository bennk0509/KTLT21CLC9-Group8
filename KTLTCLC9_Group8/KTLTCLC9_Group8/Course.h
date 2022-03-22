#ifndef  _COURSE_H
#define _COURSE_H
#include "Struct.h"

void inputSemester(Semester* pSemester);
bool CreateNewSemester(Semester* pSemester, string yearName, string semesterName);
void addNewCourse(Course*& pCourse, string semesterName, string yearName, Course*& newCourse, int add);
void updateCourseData(Course *head);
void updateCourse(Course *head, string ID);
void deleteCourse(Course *&head, string ID);

#endif // ! _COURSE_H

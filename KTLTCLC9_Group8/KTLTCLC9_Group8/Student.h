#ifndef  _STUDENT_H_
#define _STUDENT_H_

#include "Struct.h"

void EnrollCourse(Course*& pCourse, Student*& curStudent, string CourseID, string yearName, Semester* pSemester);
void viewEnrollList(Course* pEnrollCourse, string semesterName);
void removeEnrolledCourse(Course *&ELhead, string ID);

#endif // ! _STUDENT_H_

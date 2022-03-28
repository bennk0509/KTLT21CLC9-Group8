#ifndef  _STUDENT_H
#define _STUDENT_H

#include "Struct.h"

void EnrollCourse(Course*& pCourse, Student*& pStudent, string CourseID, string studentID, string yearName, string semesterName);
void viewEnrollList(Course* pEnrollCourse, string semesterName);
void removeEnrolledCourse(Course *&ELhead, string ID);

#endif // ! _STUDENT_H

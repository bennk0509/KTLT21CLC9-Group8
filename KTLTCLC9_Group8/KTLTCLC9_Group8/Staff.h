#ifndef  _STAFF_H
#define _STAFF_H

#include "Struct.h"

void viewClassesList(Year *pYear);
void viewStudentListInCourse(Student *head);
void CreateNewYear(Year*& pYear, string yearname, int k);
void exportStudentToCsv(Student* pStuInCourse, string courseID);
void ViewScoreBoardOfCourse(Course *pCourse,string courseID);

#endif // ! _STUDENT_H

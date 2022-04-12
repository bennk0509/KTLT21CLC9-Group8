#ifndef  _STAFF_H
#define _STAFF_H

#include "Struct.h"

void viewClassesList(Year *pYear);
void viewStudentListInCourse(Student *head);
void CreateNewYear(Year*& pYear, string yearname, int k);
void exportStudentToCsv(Student* pStuInCourse, string courseID);
void ViewScoreBoardOfCourse(Course *pCourse,string courseID);
void importScoreboard(string courseID, Year* curYear, Semester*& curSemester);
Student* findStudent(Year* curYear, string stuID);
void viewScoreBoardOfClass(Student* pStudent, Semester* pSemester, Semester* curSemester);
void UpdateStudentResult(Scoreboard* &pScoreboard, string studenID);
void viewListOfStudentsInClass(Year* pYear, string className);
#endif // ! _STAFF_H

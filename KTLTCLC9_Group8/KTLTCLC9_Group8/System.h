#ifndef _SYSTEM_H_
#define _SYSTEM_H_
bool LogIn(int input);
void cont(char& contchar, bool& login);
bool changeYear(Year*& pYear, string& yearname, Year* &curYear, bool& yearcheck);
void changeSemester(Year* pYear, Semester*& curSemester, string& semesterName, bool& semestercheck);
void inputNewCourse(Course*& newCourse);
#endif // !_SYSTEM_H_


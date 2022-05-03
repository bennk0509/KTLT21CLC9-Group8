#ifndef _SYSTEM_H_
#define _SYSTEM_H_
bool LogIn(int input, string &account);
void cont(char& contchar, bool& login);
bool changeYear(Year*& pYear, string& yearname, Year* &curYear, bool& yearcheck);
void changeSemester(Year* pYear, Semester*& curSemester, string& semesterName, bool& semestercheck);
void inputNewCourse(Course*& newCourse, Semester* curSemester);
bool logStudent(string account, Year* pYear, Student*& curStudent, Year*& currentYear);
void loadData(Year*& pYear, ifstream& yearin);
void ChangePassword(int role);
void courseDate(int& d1, int& d2, int& s1, int& s2, Course* &curCourse);
#endif // !_SYSTEM_H_


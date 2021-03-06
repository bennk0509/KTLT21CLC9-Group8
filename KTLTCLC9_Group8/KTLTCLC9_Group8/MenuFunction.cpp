#include <iostream>
#include <string>
#include "Struct.h"
#include "Class.h"
#include "Course.h"
#include "Staff.h"
#include "System.h"
#include "Student.h"
using namespace std;

void cont(char& contchar, bool& login)
{
	do
	{
		cout << "Do you want to continue? (y/n): ";
		cin >> contchar;
		system("cls");

	} while (contchar != 'y' && contchar != 'n');
	if (contchar == 'n')
		login = false;
}

bool changeYear(Year*& pYear, string& yearname, Year* &curYear, bool &yearcheck)
{
	curYear = pYear;
	do
	{
		system("cls");
		cout << "Input year (Format: 20xx): ";
		cin.ignore(1000, '\n');
		cin >> yearname;
		if (yearname.length() != 4 || atoi(yearname.c_str()) == 0)
		{
			
			cout << "Format is not correct, please try again";
			system("pause");

		}
	} while (yearname.length() != 4 || atoi(yearname.c_str()) == 0);
	if (pYear == nullptr)
	{
		
		cout << "This year does not exist.";
		system("pause");
		return false;
	}
	else
	{
		if (pYear->yearNext == nullptr)
		{
			if (pYear->YearName.compare(yearname) == 0)
			{
				yearcheck = true;
				curYear = pYear;
			}
		}
		else
		{
			curYear = pYear;
			while (curYear != nullptr)
			{
				if (curYear->YearName.compare(yearname) == 0)
				{
					yearcheck = true;
					break;
				}
				curYear = curYear->yearNext;
			}
		}
	}
	if (curYear == nullptr)
	{
		
		cout << "This year does not exist.\n";
		yearcheck = false;
		system("pause");
		return false;
	}
		
	if (!yearcheck && pYear != nullptr)
	{
		
		cout << "This year does not exist.\n";
		yearcheck = false;
		system("pause");
		return false;
	}
	return true;
}

void changeSemester(Year* pYear, Semester*& curSemester, string& semesterName, bool &semestercheck)
{
	do
	{
		cout << "Input semester name (1 to 12): ";
		cin >> semesterName;
		if (stoi(semesterName) < 1 || stoi(semesterName) > 12)
		{
			cout << "Incorrect input, please try again\n";
		}
	} while (stoi(semesterName) < 1 || stoi(semesterName) > 12);

	if (pYear->pSemester == nullptr)
	{
		cout << "This semester does not exist.";

	}
	else
	{
		if (pYear->pSemester->semesterNext == nullptr)
		{
			if (pYear->pSemester->semesterName.compare(semesterName) == 0)
			{
				semestercheck = true;
				curSemester = pYear->pSemester;
			}
		}
		else
		{
			curSemester = pYear->pSemester;
			while (curSemester != nullptr)
			{
				if (curSemester->semesterName.compare(semesterName) == 0)
				{
					semestercheck = true;
					break;
				}
				curSemester = curSemester->semesterNext;
			}
		}
	}
	if (curSemester == nullptr)
	{
		cout << "This semester is not exist.";
		semestercheck = false;
		return;
	}
	if (!semestercheck && pYear->pSemester != nullptr)
	{
		cout << "This semester is not exist.";
		semestercheck = false;
		return;
	}
		
}

void loadData(Year*& pYear, ifstream &yearin)		
{
	Year* curYear = pYear;
	while (yearin.peek() != EOF)
	{
		string yearName;
		yearin >> yearName;
		CreateNewYear(pYear, yearName, 0);
		Year* curYear = pYear;
		while (curYear->YearName.compare(yearName) != 0)
			curYear = curYear->yearNext;
		string classdir = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + curYear->YearName + "\\Class.txt";
		ifstream classin(classdir);
		while (classin.peek() != EOF)
		{
			string className;
			classin >> className;
			createNewClass(curYear->pClass, curYear->YearName, className, 0);
			Class* curClass = curYear->pClass;
			while (curClass->className.compare(className) != 0)
				curClass = curClass->classNext;
			string studentdir = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + curYear->YearName + "\\" + curClass->className + "\\Student.txt";
			ifstream studentin(studentdir);
			string s;
			while (getline(studentin,s))
			{
				int count = 0;
				Student* pS = new Student;
				int size = s.length();
				if (s[1] != ',')
					pS->ID = s.substr(3, 8);
				else
					pS->ID = s.substr(2, 8);
				pS->gender = s[size - 1] - 48;
				for (int i = size - 3; i > 0; i--)
				{
					if (s[i] == ',')
						break;
					count++;
				}
				pS->classname = s.substr(size - count - 2, count);
				pS->DOB.day = stoi(s.substr(size - count - 5, 2));
				pS->DOB.month = stoi(s.substr(size - count - 8, 2));
				pS->DOB.year = stoi(s.substr(size - count - 13, 4));
				int k = count;
				count = 0;
				for (int i = size - k - 15; i > 0; i--)
				{
					if (s[i] == ',') break;
					count++;
				}
				if (s[1] != ',')
					pS->name = s.substr(12, count);
				else
					pS->name = s.substr(11, count);

				addNewStudent(curClass->pStudent, curYear->YearName, curClass->className, pS, 0);
				Student* curStudent = curClass->pStudent;
				while (curStudent->name.compare(pS->name) != 0)
					curStudent = curStudent->studentNext;
				string ecdir = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + curYear->YearName + "\\" + curClass->className + "\\" + curStudent->ID + ".txt";
				ifstream ecin(ecdir);
				if (ecin)
				{
					for (int i = 0; i < 4; i++)
						for (int j = 0; j < 7; j++)
							ecin >> curStudent->coursesenrolled[i][j];
				}
				while (!ecin.eof() && ecin)
				{
					Course* ECourse = new Course;
					ecin >> ECourse->id;
					ecin.ignore(1000, '\n');
					getline(ecin, ECourse->name);
					getline(ecin, ECourse->lecturerName);
					ecin >> ECourse->sSemester;
					ecin >> ECourse->numberOfCredits;
					ecin >> ECourse->maxStudent;
					ecin >> ECourse->curStudentNum;
					ecin >> ECourse->date.d1 >> ECourse->date.d2 >> ECourse->date.s1 >> ECourse->date.s2;
					Course* curECourse = curStudent->EnrolledCourses;
					if (curStudent->EnrolledCourses == nullptr)
					{
						curStudent->EnrolledCourses = ECourse;
						curECourse = curStudent->EnrolledCourses;
					}
						
					else
					{
						while (curECourse->courseNext != nullptr)
							curECourse = curECourse->courseNext;
						curECourse->courseNext = ECourse;
						curECourse = curECourse->courseNext;
					}

				}
			}
			studentin.close();
		}
		classin.close();
		string semdir = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + yearName + "\\Semester\\Semester.txt";
		fstream semin;
		Semester* newSem;
		semin.open(semdir, ios::in);
		while (!semin.eof() && semin)
		{
			newSem = new Semester;
			Semester* curSemester = curYear->pSemester;
			semin >> newSem->semesterName;
			semin >> newSem->startDate.day;
			semin >> newSem->startDate.month;
			semin >> newSem->startDate.year;
			semin >> newSem->endDate.day;
			semin >> newSem->endDate.month;
			semin >> newSem->endDate.year;
			semin >> newSem->startReg.day;
			semin >> newSem->startReg.month;
			semin >> newSem->startReg.year;
			semin >> newSem->endReg.day;
			semin >> newSem->endReg.month;
			semin >> newSem->endReg.year;
			if (curYear->pSemester == nullptr)
			{
				curYear->pSemester = newSem;
				curYear->pSemester->semesterNext = nullptr;
				curSemester = curYear->pSemester;
			}
			else
			{
				while (curSemester->semesterNext != nullptr)
					curSemester = curSemester->semesterNext;
				curSemester->semesterNext = newSem;
				curSemester = curSemester->semesterNext;
				curSemester->semesterNext = nullptr;
			}
			string coursedir = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + curYear->YearName + "\\Semester\\" + curSemester->semesterName + "\\Course.txt";
			Course* newCourse ;
			ifstream coursein(coursedir);
			while (!coursein.eof() && coursein)
			{
				newCourse = new Course;
				coursein >> newCourse->id;
				if (newCourse->id.compare("") == 0)
					break;
				coursein.ignore(1000, '\n');
				getline(coursein, newCourse->name);
				getline(coursein, newCourse->lecturerName);
				coursein >> newCourse->sSemester;
				coursein >> newCourse->numberOfCredits;
				coursein >> newCourse->maxStudent;
				coursein >> newCourse->curStudentNum;
				coursein >> newCourse->date.d1;
				coursein >> newCourse->date.d2;
				coursein >> newCourse->date.s1;
				coursein >> newCourse->date.s2;
				Course* curCourse = curSemester->pCourse;
				if (curSemester->pCourse == nullptr)
				{
					curSemester->pCourse = newCourse;
					curSemester->pCourse->courseNext = nullptr;
					curCourse = curSemester->pCourse;
				}
				else
				{
					while (curCourse->courseNext != nullptr)
						curCourse = curCourse->courseNext;
					curCourse->courseNext = newCourse;
					curCourse = curCourse->courseNext;
					curCourse-> courseNext = nullptr;
				}
				string cstudir = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\Data\\YearName\\" + curYear->YearName + "\\Semester\\" + curSemester->semesterName + "\\" + curCourse->id + "\\Student.txt";
				ifstream cstuin(cstudir);
				string cstudent;
				Student* StInCourse;
				while (getline(cstuin,cstudent) && cstuin)
				{
					int count = 0;
					StInCourse = new Student;
					int size = cstudent.length();
					if (cstudent[1] != ',')
						StInCourse->ID = cstudent.substr(3, 8);
					else
						StInCourse->ID = cstudent.substr(2, 8);
					StInCourse->gender = cstudent[size - 1] - 48;
					for (int i = size - 3; i > 0; i--)
					{
						if (cstudent[i] == ',')
							break;
						count++;
					}
					StInCourse->classname = cstudent.substr(size - count - 2, count);
					StInCourse->DOB.day = stoi(cstudent.substr(size - count - 5, 2));
					StInCourse->DOB.month = stoi(cstudent.substr(size - count - 8, 2));
					StInCourse->DOB.year = stoi(cstudent.substr(size - count - 13, 4));
					int k = count;
					count = 0;
					for (int i = size - k - 15; i > 0; i--)
					{
						if (cstudent[i] == ',') break;
						count++;
					}
					if (cstudent[1] != ',')
						StInCourse->name = cstudent.substr(12, count);
					else
						StInCourse->name = cstudent.substr(11, count);
					Student* curStudent = curCourse->pStudent;
					if (curCourse->pStudent == nullptr)
					{
						curCourse->pStudent = StInCourse;
						curCourse->pStudent->studentNext = nullptr;
						curStudent = curCourse->pStudent;
					}
					else
					{
						while (curCourse->pStudent != nullptr)
							curStudent = curStudent->studentNext;
						curStudent->studentNext = StInCourse;
						curStudent = curStudent->studentNext;
						curStudent->studentNext = nullptr;
					}
				}
				cstuin.close();
				string sbdir = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + curYear->YearName + "\\Semester" + "\\" + curSemester->semesterName + "\\" + curCourse->id + "\\Scoreboard.txt";
				Scoreboard* newSB;
				ifstream sbin(sbdir);
				Scoreboard* curSB = curCourse->pScoreboard;
				string temp;
				while (!sbin.eof() && sbin)
				{

					newSB = new Scoreboard;
					getline(sbin, temp, ',');
					getline(sbin, temp, ',');
					if (findStudent(curYear, temp) == nullptr) //if studnent id doesnt exist, skip that info
					{
						getline(sbin, temp, '\n');
						continue;
					}
					newSB->stu = findStudent(curYear, temp);
					getline(sbin, temp, ',');
					getline(sbin, temp, ',');
					newSB->total = stof(temp);
					getline(sbin, temp, ',');
					newSB->final = stof(temp);
					getline(sbin, temp, ',');
					newSB->midterm = stof(temp);
					getline(sbin, temp, '\n');
					newSB->bonus = stof(temp);
					if (curCourse->pScoreboard == nullptr)
					{
						curCourse->pScoreboard = newSB;
						curSB = curCourse->pScoreboard;
					}
					else
					{
						curSB->scoreboardNext = newSB;
						curSB = curSB->scoreboardNext;
					}

						
					
				}
			}
		}
		semin.close();
	}
}
bool Check1(string a)
{
	if(a.compare("MON") == 0 || a.compare("TUE") == 0|| a.compare("WED")== 0||a.compare("THU") == 0|| a.compare("FRI") == 0||a.compare("SAT") == 0) return true;
	return false;
}
bool Check2(string a)
{
	if(a.compare("7:30") == 0|| a.compare("9:30")|| a.compare("13:30")||a.compare("15:30")) return true;
	return false;
}
void inputNewCourse(Course*& newCourse, Semester* curSemester)
{
	newCourse->sSemester = curSemester->semesterName;
	cout << "Course ID: ";
	cin >> newCourse->id;
	cout << "Course name: ";
	cin.ignore(1000, '\n');
	getline(cin, newCourse->name);
	cout << "Course's lecturer's name: ";
	getline(cin, newCourse->lecturerName);
	cout << "Number of credits: ";
	cin >> newCourse->numberOfCredits;
	cout << "Course date 1: ";
	cin >> newCourse->date.d1;
	while(Check1(newCourse->date.d1) == false)
	{
		cout << "ERROR, Please try again (input 3 first letter of date)";
		cin >> newCourse->date.d1;
	}
	cout << "Course date 2: ";
	cin >> newCourse->date.d2;
	while(Check1(newCourse->date.d2) == false)
	{
		cout << "ERROR, Please try again (input 3 first letter of date)";
		cin >> newCourse->date.d2;
	}
	cout << "Course shift 1: ";
	cin >> newCourse->date.s1;
	while(Check2(newCourse->date.s1) == false)
	{
		cout << "ERROR, Please try again (input 7:30,9:30,13:30,15:30)";
		cin >> newCourse->date.s1;
	}
	cout << "Course shift 2: ";
	cin >> newCourse->date.s2;
	while(Check2(newCourse->date.s2) == false)
	{
		cout << "ERROR, Please try again (input 7:30,9:30,13:30,15:30)";
		cin >> newCourse->date.s2;
	}
	cout << "Course max student: ";
	cin >> newCourse->maxStudent;
}

bool logStudent(string account, Year* pYear, Student* &curStudent, Year* &currentYear)
{
	bool acccheck = false;
	if (pYear == nullptr)
	{
		cout << "This account does not exist.\n";
		system("pause");
		return false;
	}
	Year* curYear = pYear;
	while (curYear != nullptr)
	{
		if (curYear->YearName.substr(curYear->YearName.length() - 2, 2).compare(account.substr(0, 2)) == 0)
		{
			
			currentYear = curYear;
			break;
		}
		curYear = curYear->yearNext;
	}
	if (curYear == nullptr)
	{
		cout << "This account does not exist.\n";
		system("pause");
		return false;
	}
	
	Class* curClass = curYear->pClass;
	while (curClass != nullptr)
	{
		Student* curStu = curClass->pStudent;
		while (curStu != nullptr)
		{
			if (curStu->ID.compare(account) == 0)
			{
				acccheck = true;
				curStudent = curStu;
				break;
			}
			curStu = curStu->studentNext;
		}
		curClass = curClass->classNext;
	}
	if (!acccheck)
	{
		cout << "This account does not exist.\n";
		system("pause");
		return false;
	}
	return true;
}

void courseDate(int& d1, int& d2, int& s1, int& s2, Course* &curCourse)
{
	if (curCourse->date.d1.compare("MON") == 0) d1 = 0;
	else if (curCourse->date.d1.compare("TUE") == 0) d1 = 1;
	else if (curCourse->date.d1.compare("WED") == 0) d1 = 2;
	else if (curCourse->date.d1.compare("THU") == 0) d1 = 3;
	else if (curCourse->date.d1.compare("FRI") == 0) d1 = 4;
	else if (curCourse->date.d1.compare("SAT") == 0) d1 = 5;
	else if (curCourse->date.d1.compare("SUN") == 0) d1 = 6;

	if (curCourse->date.d2.compare("MON") == 0) d2 = 0;
	else if (curCourse->date.d2.compare("TUE") == 0) d2 = 1;
	else if (curCourse->date.d2.compare("WED") == 0) d2 = 2;
	else if (curCourse->date.d2.compare("THU") == 0) d2 = 3;
	else if (curCourse->date.d2.compare("FRI") == 0) d2 = 4;
	else if (curCourse->date.d2.compare("SAT") == 0) d2 = 5;
	else if (curCourse->date.d2.compare("SUN") == 0) d2 = 6;

	if (curCourse->date.s1.compare("7:30") == 0) s1 = 0;
	else if (curCourse->date.s1.compare("9:30") == 0) s1 = 1;
	else if (curCourse->date.s1.compare("13:30") == 0) s1 = 2;
	else if (curCourse->date.s1.compare("15:30") == 0) s1 = 3;

	if (curCourse->date.s2.compare("7:30") == 0) s2 = 0;
	else if (curCourse->date.s2.compare("9:30") == 0) s2 = 1;
	else if (curCourse->date.s2.compare("13:30") == 0) s2 = 2;
	else if (curCourse->date.s2.compare("15:30") == 0) s2 = 3;
}

void loadCourse(Semester* pSemester, Student* &curStudent, Year* curYear)
{
	string ecdir = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + curYear->YearName + "\\" + curStudent->classname + "\\" + curStudent->ID + "_" + pSemester->semesterName + ".txt";
	ifstream ecin(ecdir);
	curStudent->EnrolledCourses = nullptr;
	if (!ecin)
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 7; j++)
				curStudent->coursesenrolled[i][j] = 0;
	}
	if (ecin)
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 7; j++)
				ecin >> curStudent->coursesenrolled[i][j];
	}
	while (!ecin.eof() && ecin)
	{
		Course* ECourse = new Course;
		ecin >> ECourse->id;
		ecin.ignore(1000, '\n');
		getline(ecin, ECourse->name);
		getline(ecin, ECourse->lecturerName);
		ecin >> ECourse->sSemester;
		ecin >> ECourse->numberOfCredits;
		ecin >> ECourse->maxStudent;
		ecin >> ECourse->curStudentNum;
		ecin >> ECourse->date.d1 >> ECourse->date.d2 >> ECourse->date.s1 >> ECourse->date.s2;
		Course* curECourse = curStudent->EnrolledCourses;
		if (curStudent->EnrolledCourses == nullptr)
		{
			curStudent->EnrolledCourses = ECourse;
			curECourse = curStudent->EnrolledCourses;
		}

		else
		{
			while (curECourse->courseNext != nullptr)
				curECourse = curECourse->courseNext;
			curECourse->courseNext = ECourse;
			curECourse = curECourse->courseNext;
		}
	}
}
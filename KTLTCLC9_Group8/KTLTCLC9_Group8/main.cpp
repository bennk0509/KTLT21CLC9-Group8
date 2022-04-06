#include <iostream>
#include <fstream>
#include "Struct.h"
#include "Class.h"
#include "Course.h"
#include "Staff.h"
#include "System.h"
#include "Student.h"
using namespace std;



int main()
{
	int add = 0;
	string classname, courseID, account;
	string yearName, disk = "", semesterName;
	Year* pYear = nullptr, *curYear = nullptr;
	Student* curStudent = nullptr;
	Semester* curSemester = nullptr;
	string yearname = "";
	int choice;
	Student* newStu = nullptr;
	Course* newCourse = nullptr;
	ifstream fin;
	bool yearcheck = false, semestercheck = false;
	char contchar,sdefault;
	ifstream yearin("C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\Year.txt");
	loadData(pYear, yearin);
	do
	{
		system("cls");
		cout << "COURSE REGISTATION SYSTEM\n\n";
		cout << "You are logging as: \n 1. Academic Staff \n 2. Student \n 0. Exit \n >>>>>> ";
		cin >> choice;
		bool login;
		switch (choice)
		{
			int choice2;
			case 1:
				system("cls");
				login = LogIn(choice,account);
				while (login)
				{
					system("cls");
					if (yearcheck)
						cout << "***Year: " << curYear->YearName << endl;
					if (semestercheck)
						cout << "***Semester: " << curSemester->semesterName << endl;
					cout << "1. Choose year\n";
					cout << "2. Create school year\n";
					cout << "3. Create classes\n";
					cout << "4. Add student\n";
					cout << "5. Add student using CSV\n";
					cout << "6. View list of classes.\n";
					cout << "7. View list of students in a class.\n";
					cout << "8. Create a semester\n";
					cout << "9. Choose semester\n";
					cout << "10. Create course registration session\n";
					cout << "11. Add a course.\n";
					cout << "12. View the list of courses.\n";
					cout << "13. Update course information.\n";
					cout << "14. Delete a course.\n";
					cout << "15.\n";
					cout << "0. Back\n";
					do
					{
						cout << ">>> ";
						cin >> choice2;
						if (!yearcheck && (choice2 > 2))
							cout << "You have to choose a year in order to use this function, please try 1 or 2.\n";
						else if (!semestercheck && choice2 > 7 && yearcheck)
							cout << "You have to choose a semester in order to use this function, please try 6 or 7.\n";
					} while ((!yearcheck && choice2 > 2) || (!semestercheck && choice2 > 9 && yearcheck));
					switch (choice2)
					{
					case 1:
						if(changeYear(pYear, yearname, curYear, yearcheck))
						{
							curSemester = nullptr;
							semestercheck = false;
						}
						cont(contchar, login);
						break;
					case 2:
						
						do
						{
							system("cls");
							cout << "Input year (Format: 20xx): ";
							cin >> yearname;
							if (yearname.length() != 4 || atoi(yearname.c_str()) == 0)
							{
								cout << "Format is not correct, please try again";
							
							}
						} while (yearname.length() != 4 || atoi(yearname.c_str()) == 0);
						CreateNewYear(pYear, yearname,1);
						
						cont(contchar, login);
						break;
					
					case 3:
						add = 1;
						cout << "Input class name: ";
						cin >> classname;
						createNewClass(curYear->pClass, curYear->YearName, classname, add);
						cont(contchar, login);
						break;
					case 4:											//date of birth needs input 2 times
					system("cls");
					newStu = new Student;
					cout << "Input class name: ";
					cin >> classname;
					if (curYear->pClass == nullptr)
						cout << "Class is not exist.";
					for (Class* i = curYear->pClass; i != nullptr; i = i->classNext)
					{
						if (i->className.compare(classname) == 0)
						{
							inputStudent(newStu);
							addNewStudent(i->pStudent, yearName, classname, newStu,1);
							break;
						}
						else if (i->classNext == nullptr && i->className.compare(classname) != 0)
							cout << "Class is not exist.";
					}
					
					cont(contchar, login);
						break;
					case 5:
						cout << "Input file's directorty (example: C:\\\data\\\student.csv) or input 'default' to choose default path\n";
						cout << ">>>>";
						cin >> disk;
						if (disk.compare("default") == 0)
							disk = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\StudentCSV\\20CTT1_Student.csv";
						fin.open(disk);
						if (!fin)
							cout << "Cannot open file.\n";
						else
						{
							cout << "Enter class: ";
							cin >> classname;
							for (Class* i = curYear->pClass; i != nullptr; i = i->classNext)
							{
								if (i->className.compare(classname) == 0)
								{
									importStudentCSV(i->pStudent, fin, curYear->YearName, i->className);
									cout << "Import successfully.";
									break;
								}
								else if (i->classNext == nullptr && i->className.compare(classname) != 0)
									cout << "Class is not exist.";
							}
						}
							
						cont(contchar, login);
						break;
					case 6:
						viewClassesList(curYear);
						cont(contchar, login);
						break;
					case 7:					//NOT DONE YET
						viewListOfStudentsInClass(curYear, "21CLC09");
						cont(contchar, login);
						break;
					case 8:
						do
						{
							cout << "Input semester name (1,2 or 3): ";
							cin >> semesterName;
							if (semesterName != "1" && semesterName != "2" && semesterName != "3")
							{
								cout << "Incorrect input, please try again\n";
							}
						} while (semesterName != "1" && semesterName != "2" && semesterName != "3");
						CreateNewSemester(curYear->pSemester,curYear->YearName,semesterName,curSemester,semestercheck,sdefault);
						cont(contchar, login);
						break;
					case 9:
						changeSemester(curYear, curSemester, semesterName, semestercheck);
						cont(contchar, login);
						break;
					case 10:
						CreateCourseRegistrationSession(curSemester,curYear->YearName);
						cont(contchar, login);
						break;
					case 11:
						system("cls");
						newCourse = new Course;
						inputNewCourse(newCourse);
						addNewCourse(curSemester->pCourse, curSemester->semesterName, curYear->YearName, newCourse, 1);
						cont(contchar, login);
						break;
					case 12:
						system("cls");
						ViewListCourse(curSemester->pCourse);
						cont(contchar, login);
						break;
					case 13:
						system("cls");
						cout << "Input course ID: ";
						cin >> courseID;
						updateCourse(curSemester->pCourse, courseID);
						cont(contchar, login);
						break;
					case 14:
						system("cls");
						cout << "Input course ID: ";
						cin >> courseID;
						deleteCourse(curSemester->pCourse, courseID);
						cont(contchar, login);
						break;
					case 15: // Chua Xong
						system("cls");
						importScoreboard(courseID, curYear, curSemester);
						cont(contchar, login);
						break;
					case 0:
						login = false;
						curYear = nullptr;
						curSemester = nullptr;
						semestercheck = false;
						break;
					default:
						break;
					}
				}
				break;
			case 2:							//Not done yet!
				system("cls");   
				login = LogIn(choice,account);
				if (login)
				{
					bool logcheck = logStudent(account, pYear, curStudent,curYear);
					if (!logcheck)
						login = false;
				}
				while (login)
				{
					system("cls");
					if (semestercheck)
						cout << "***Semester: " << curSemester->semesterName << endl;
					cout << "1. Choose semester.\n";
					cout << "2. Enroll in a course.\n";
					cout << "3. View list of enrolled courses.\n";
					cout << "4. Remove course from the enrolled list.\n";
					cout << "0. Back.\n";
					do
					{
						cout << ">>> ";
						cin >> choice2;
						if (!semestercheck && choice2 > 1)
							cout << "You have to choose a semester in order to use this function\n";
					} while (!semestercheck && choice2 > 1);
					switch (choice2)
					{
					case 1:
						changeSemester(curYear, curSemester, semesterName, semestercheck);
						cont(contchar, login);
						break;
					case 2:
						system("cls");
						EnrollCourse(curSemester->pCourse, curStudent, courseID,curYear->YearName,curSemester);
						cont(contchar, login);
						break;
					case 3:
						system("cls");
						viewEnrollList(curStudent->EnrolledCourses, curSemester->semesterName);
						cont(contchar, login);
						break;
					case 4:
						system("cls");
						cout << "Enter course ID: ";
						cin >> courseID;
						removeEnrolledCourse(curStudent->EnrolledCourses, courseID, curSemester);	
					case 0:
						login = false;
						curYear = nullptr;
						curSemester = nullptr;
						semestercheck = false;
						break;
					}
				}
		}
	} while (choice != 0);
	return 0;
}
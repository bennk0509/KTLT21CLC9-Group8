#include "Struct.h"
#include "Staff.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>

using namespace std;

void exportStudentToCsv(Student* pStuInCourse, string courseID) {
	/*string dirD = "C:\\Data\\File_csv\\Student.csv\\";
	string c;
	strcat(c, dirD);
	strcat(c, courseID);
	strcat(c, ".csv");
	ofstream fout;
	fout.open(c);
	if (fout.is_open()) {
		int cnt = 0;
		while (pStuInCourse) {
			fout << ++cnt << "," << pStuInCourse->studentID << "," << pStuInCourse->Name << "," << pStuInCourse->DOB.year << "-" << pStuInCourse -> DOB.month << "-" << 
			pStuInCourse -> DOB.day << "," << pStuInCourse->sClass << "," << pStuInCourse->gender;
			fout << '\n'C
			pStuInCourse = pStuInCourse->studentNext;
		}
		cout << "Done! The list of students has been exported into the file C:\Data/File_csv/Student.csv" << courseID << ".csv\n\n";
		system("pause");
		system("cls");
	}
	fout.close();*/
}
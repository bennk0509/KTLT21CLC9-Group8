#include "Struct.h"
#include "Staff.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void exportStudentToCsv(Student* pStuInCourse, string courseID) {
	_mkdir("C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\ExportedCSV");
	string dirD = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\ExportedCSV";
	dirD += "\\" + courseID + "_Student.csv";
	ofstream fout;
	fout.open(dirD);
	if (fout.is_open()) {
		int cnt = 0;
		Student* pCur = pStuInCourse;
		while (pCur != nullptr) {
			fout << cnt++ << ",";
			fout << pCur->ID << ",";
			fout << pCur->name << ",";
			fout << pCur->DOB.year << "-";
			if (pCur->DOB.month < 10)
				fout << "0" << pCur->DOB.month;
			else
				fout << pCur->DOB.month;
			fout << "-";
			if (pCur->DOB.day < 10)
				fout << "0" << pCur->DOB.day;
			else
				fout << pCur->DOB.day;
			fout << ",";
			fout << pCur->classname << ",";
			fout << pCur->gender << endl;
			pCur = pCur->studentNext;
		}
		cout << "Done! The list of students has been exported into the file _______________ \n\n";
		system("pause");
		system("cls");
	}
	fout.close();
}
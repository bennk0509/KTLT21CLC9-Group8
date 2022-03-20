#ifndef  _CLASS_H
#define _CLASS_H
#include <fstream>
using namespace std;

#include "Struct.h"

Student* inputStudentCSV(ifstream& studentcsv);
void importStudentCSV(Student*& pStudent, ifstream& studentcsv, string yearname, string classname);
void exportStudent(Student* pStudent, fstream& fout);
void addNewStudent(Student*& pStudent, string yearName, string className, Student*& newStu);
void inputStudent(Student*& newStu);
void CreateNewYear(Year *&pYear, string yearname);



#endif // ! _CLASS_H

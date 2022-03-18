#ifndef  _CLASS_H
#define _CLASS_H
#include <fstream>
using namespace std;

#include "Struct.h"


Student* inputStudent(ifstream& studentcsv);
void importStudentCSV(Student*& pStudent, ifstream& studentcsv);
void exportStudent(Student* pStudent, fstream& fout);



#endif // ! _CLASS_H

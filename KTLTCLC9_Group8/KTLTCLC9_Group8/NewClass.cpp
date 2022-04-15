#include <iostream>
#include <fstream>
#include <string.h>
#include "Class.h"
#include "Struct.h"

using namespace std;

void createNewClass(Class*& pClass, string yearName, string ClassName, int add) {
	Class* cur = pClass;

	while (cur != nullptr) {
		if (cur->className.compare(ClassName) == 0) {
			cout << "Failed to create a new class!!\n";
			cout << "The class you are about to create has already existed!!\n";
			system("pause");
			system("cls");
			return;
		}
		cur = cur -> classNext;
	}

	string dirD = "C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + yearName + "\\";

	ofstream fout;
	if (add)
		fout.open("C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\YearName\\" + yearName + "\\Class.txt");

	cur = pClass;

	if (pClass == nullptr) {
		pClass = new Class;
		pClass -> className = ClassName;
		if (add)
			fout << pClass -> className;
	}
	else {
		while (cur -> classNext != nullptr) {
			if (add)
				fout << cur -> className << '\n';
			cur = cur -> classNext;
		}
		if (add)
			fout << cur -> className << '\n';
		cur -> classNext = new Class;
		cur = cur -> classNext;
		cur -> className = ClassName;
		if (add)
			fout << cur -> className;
	}
	if (add)
	{
		fout.close();
		cout << "Add new class successfully.\n";
		system("pause");
	}
		
	dirD += ClassName;
	int check = _mkdir(dirD.c_str());
}

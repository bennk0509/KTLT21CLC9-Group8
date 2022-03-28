#include <iostream>
#include <fstream>
#include <string.h>
#include "Struct.h"

using namespace std;

bool LogIn(){
	char ad[200] = "";
	bool login = false;
	bool StillLog = true;

	strcat(ad, "C:\\Github\\KTLTCLC9_Group8\\Data\\Account.txt");
	while(!login || StillLog) {
		cout << "Do you want to log in?"<<endl;
		cout << "0: No"<<endl;
		cout << "1: Yes"<<endl;

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 1 || (respond[0] < '0' || '1' < respond[0])) {
			cout << "Invalid, please try again\n\n";
			continue;
		}

		int x = respond[0] - '0';

		delete[] respond;	
		/*if (x != 0 && x != 1) {
			cout << "Invalid, please try again\n\n";
			continue;
		}*/

		if(x == 0){
			StillLog = false;
			break;
		}
		char Username[101]; char Password[101];
		cout << "Please input Username: ";
		cin >> Username;
		cout << "Please input Password: ";
		cin >> Password;
		ifstream fin(ad);
		char name[101], pass[101];
		while(fin >> name && fin >> pass){
			if(strcmp(name,Username) == 0 && strcmp(pass, Password) == 0){
				system("cls");
				cout << "You have logged in!\n\n";
				login = true;
				break;
			}
		}
		if (login)
			break;
		system("cls");
		cout << "Wrong username or password, please try again.\n\n";
	}
	return login;
}
#include "Struct.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void ChangePassword()
{
    fstream input, output;
    string accDir="C:\\Users\\ADMIN\\OneDrive\\Documents\\GitHub\\KTLT21CLC9-Group8\\Data\\Account.txt";
    input.open(accDir, ios::in);
    output.open(accDir, ios::out);
    if(input.fail())
    {
        cout<<"Account file opening failed!";
        return;
    }
    string username;
    cout<<"Enter username: ";
    cin>>username;
    string password;
    cout<<"Enter password: ";
    cin>>password;
    Account *head=nullptr;
    string temp1, temp2;
    while(!input.eof())
    {
        input>>temp1;
        input>>temp2;
        Account *newAcc= new Account;
        newAcc->username=temp1;
        newAcc->password=temp2;
        newAcc->nextAcc=head;
        head=newAcc;
    }
    Account *cur=head;
    while(cur!=nullptr)
    {
        if(cur->username==username && cur->password==password)
        {
            break;
        }
        else 
            cur=cur->nextAcc;
    }
    string newPass;
    system("cls");
    if(cur==nullptr)
    {
        cout<<"Wrong username or password!";
    }
    else
    {
        cout<<"Enter new password: ";
        cin>>newPass;
        cur->password=newPass;
        system("cls");
        cout<<"Password changed!";
    }
    cur=head;
    while(cur!=nullptr)
    {
        output<<cur->username<<" "<<cur->password<<"\n";
        cur=cur->nextAcc;
    }
    
    cur=head;
    Account* next = nullptr;
    while (cur != nullptr)
    {
        next = cur->nextAcc;
        delete cur;
        cur = next;
    }
    head=nullptr;
}

/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2023-2
  Assignment: Group Project
  Authors and IDs:
  Tran Minh Nhat (s3926629)
  Tran Tan Phat (s3836612)
  Nguyen Vo Truong Toan (s3979056)
  Le Tran Duc Huy (s3891993)
  Compiler used: g++ 8.1.0
  Created  date: 22/08/2023
  Acknowledgement: https://codereview.stackexchange.com/questions/124194/user-registration-and-login-program
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>
#include "admin.h"
using namespace std;

Admin(std::string name="", std::string username="", std::string password="",int phone=0 ): name(name), username(username), password(password),phone(phone) {};

string toString() {
    return "Admin name: " + name + " with username: " + username;
    return "Password: " + password;
}

void showInfo(Admin &cus) {
    cout << cus.toString();
}

void writetofile(string username, string password) {
    ofstream writefile;
    string file = username + ".txt";
    writefile.open(file.c_str());
    writefile << password;
    writefile.close();
}

bool login(string username, string password) {
    ifstream readfile;
    string file = username + ".txt";
    readfile.open(file.c_str());
    if (readfile.is_open()) {
        string stored_password;
        getline(readfile, stored_password);
        readfile.close();
        return stored_password == password;
    }
    return false;
}

void registerme() {
    cout << "Please enter your username: ";
    string username;
    getline(cin, username);
    cout << "Please enter your password: ";
    string password;
    getline(cin, password);
    writetofile(username, password);
}
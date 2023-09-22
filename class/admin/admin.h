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
  Acknowledgement: List the resources that you use to complete this assessment (write 'None' if you don't use any).
*/

#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
using namespace std;

class Admin {
    private:
    std::string name;
    std::string username;
    std::string password;
    double id;
    int phone;
  
    public:
    Admin(std::string name="", std::string username="", std::string password="",int phone=0 ): name(name), username(username), password(password),phone(phone) {};
    string toString();
    void showInfo();

    void writetofile(std::string username, std::string password);

    bool login(std::string username, std::string password);

    void registerme();

    std::string getName() {
	    return this->name;
    }

    void setName(std::string name) {
	    this->name = name;
    }

    std::string getUserName() {
    	return this->username;
    }
    void setUserName(std::string UserName) {
    	this->username = username;
    }

    std::string getPassword() {
    	return this->password;
    }
    void setPassword(std::string password) {
    	this->password = password;
    }
    int getPhone() {
    	return this->phone;
    }
    void setPhone(int phone) {
    	this->phone = phone;
    }
friend class Motorbike;
friend class System;
};

#endif

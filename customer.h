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

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

class Customer {
    private:
    std::string Name;
    std::string UserName;
    std::string password;
    double id;
    int phone;
    int license;

    public:
    Customer() {};
    void showInfo();

    std::string getName() {
	    return this->Name;
    }

    void setName(std::string Name) {
	    this->Name = Name;
    }

    std::string getUserName() {
    	return this->UserName;
    }
    void setUserName(std::string UserName) {
    	this->UserName = UserName;
    }

    std::string getPassword() {
    	return this->password;
    }
    void setPassword(std::string password) {
    	this->password = password;
    }

    double getId() {
    	return this->id;
    }
    void setId(double id) {
    	this->id = id;
    }

    int getPhone() {
    	return this->phone;
    }
    void setPhone(int phone) {
    	this->phone = phone;
    }

    int getLicense() {
    	return this->license;
    }
    void setLicense(int license) {
    	this->license = license;
    }

};

#endif
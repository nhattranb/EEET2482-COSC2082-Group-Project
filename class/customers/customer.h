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
using namespace std;

class Customer {
    public:
    std::string name;

    private:
    std::string username;
    std::string password;
    double id;
    int phone;
    int license;
    std::string idType;
    std::string ExpiryDate;
    double creditPoints;
    double renterRating;
    double ownerRating;

    public:
    Customer(string name, string username, string password, int id, int phone, int license): name(name), username(username), password(password), id(id), phone(phone),
            license(license) {};
    
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

    friend class Motorbike;
    friend class Rating;
};

#endif
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

#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <iostream>
#include <string>

class Motorbike {
    private:
    std::string model;
    std::string color;
    std::string engine;
    std::string location;
    int transmission;
    int year;

    public:
    std::string getModel() {
	    return this->model;
    }

    void setModel(std::string model) {
	    this->model = model;
    }

    std::string getColor() {
    	return this->color;
    }
    void setColor(std::string color) {
    	this->color = color;
    }

    std::string getEngine() {
    	return this->engine;
    }
    void setEngine(std::string engine) {
    	this->engine = engine;
    }

    std::string getLocation() {
    	return this->location;
    }
    void setLocation(std::string location) {
    	this->location = location;
    }

    int getTransmission() {
    	return this->transmission;
    }
    void setTransmission(int transmission) {
    	this->transmission = transmission;
    }

    int getYear() {
    	return this->year;
    }
    void setYear(int year) {
    	this->year = year;
    }

};

#endif
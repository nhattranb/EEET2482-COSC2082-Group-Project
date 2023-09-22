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

#ifndef POINTS_H
#define POINTS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>
#include "customer.h"
using namespace std;
class Customer;
class Point {
    private:
    int point;

    public:
    Point(int point) {
        this->point = point;
    }
    
    int getPoint() {
	    return this->point;
    }

    void setPoint(int point) {
	    this->point = point;
    } 
};

#endif
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

#ifndef RENT_H
#define RENT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Rent {
    private:
    int date;
    int month;
    int year;
    bool requests;

    public:
    Rent(int date, int month, int year);

    friend class Customer;
    friend class Motorbike;
};

#endif
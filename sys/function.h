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

#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <fstream>
#include <iomanip>
#include "class/rent/rent.h"
#include "class/motorbike/motorbike.h"
#include "class/customers/customer.h"
#include "class/rating/rating.h"
#include "class/admin/admin.h"

class Rent;

class Motorbike;

class Customer;

class Rating;

class Admin;

class Sys {
    public:
    Sys();

    void menu();
};

#endif
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

#ifndef RENTED_H
#define RENTED_H

#include <string>
#include <vector>
#include "../customers/customer.h"
#include "motorbike.h"  // Include any necessary headers for Member, Review, Request, Date, and other dependencies.

class Rented: public Customer {
protected:
    std::string model;
    std::string color;
    float engine;
    std::string location;
    int transmission;
    int yearMade;
    std::string description;

    Customer* owner;

    bool available;
    double ratingScore;
    Rent* startingDate;
    Rent* endingDate;

public:
    Rented(std::string model, std::string color, float engine,
              std::string location, int transmission, int yearMade, std::string description);

    double getRatingScore();

    void viewMotorbikeInfo();

    ~Rented();

    friend class Customer;
    friend class Motorbike;
    friend class System;
};

#endif

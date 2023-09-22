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

#include <vector>
#include <string>
#include "../customers/customer.h"
#include "../motorbike/motorbike.h"

class Rent {
private:
    int date;
    int month;
    int year;
    bool requests;

public:
    Rent(int date, int month, int year);

    std::string convertDatetoString() const;

    void requestToRent(Motorbike &motorbike, Customer &member);

    void viewRequests(const std::vector<std::string> &requests);

    void acceptRequest(std::vector<Motorbike> &motorbikes, const std::string &name, std::vector<std::string> &requests, int index);


    friend class Customer;
    friend class Motorbike;
};

#endif

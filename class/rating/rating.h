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
  Acknowledgement: ...
*/

#ifndef RATING_H
#define RATING_H

#include <iostream>
#include <vector>
#include "../motorbike/motorbike.h"
#include "../customers/customer.h"

using namespace std;

class Rating {
    private:
    int score;
    std::string comments;
    std::string memberReview;
    Motorbike* motorbike;
    Customer customer;

    public:
    Rating(int score=0, std::string comments="", std::string memberReview="") {
        this->score = score;
        this->comments = comments;
        this->memberReview = memberReview;
    }

    string toString() {
        return "score: " + to_string(score) + " - comments: " + comments;
    }

    void showRating() {
        cout << toString();
    }

    void rateRenter(Customer &c, Motorbike &m, int ratingScore, string comments);

    void rateOwner(Customer &c, Motorbike &m, int ratingScore, string comments);

    void consumingPointsPerDay();

    ~Rating();

    friend class Customer;
    friend class Motorbike;
};

#endif

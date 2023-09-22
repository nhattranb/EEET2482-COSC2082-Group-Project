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
  Acknowledgement: https://cplusplus.com/forum/general/22788/
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include "rating.h"
#include "../customers/customer.h"
#include "../motorbike/motorbike.h"
using namespace std;

void rateRenter(Customer &c, Motorbike &m, int ratingScore, string comment) {
    m.ratingScore = ratingScore;
    m.comment = comment;
}

void rateOwner(Customer &c, Motorbike &m, int ratingScore, string comment) {
    m.ratingScore = ratingScore;
    m.comment = comment;
}

void consumingPointsPerDay(Customer &c, Motorbike &m, int days) {
    // Define the points consumed per day. Adjust this value as needed.
    double pointsPerDay = 10.0;

    // Calculate the total points to be consumed based on the number of days.
    double totalPoints = pointsPerDay * static_cast<double>(days);

    // Check if the customer has enough points to cover the rental.
    if (c.getCreditPoints() >= totalPoints) {
        // Deduct the points from the customer's balance.
        c.setCreditPoints(c.getCreditPoints() - totalPoints);

        // You can perform other necessary operations here, such as updating records.

        cout << "Points consumed: " << totalPoints << " for " << days << " days of rental." << endl;
    } else {
        cout << "Insufficient points to rent the motorbike for " << days << " days." << endl;
    }
}

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
#include "customer.h"
#include "motorbike.h"
using namespace std;

void rateRenter(Customer &c, Motorbike &m, int score, string comment) {
    m.score = score;
    m.comment = comment;
}

void rateOwner(Customer &c, Motorbike &m, int score, string comment) {
    m.score = score;
    m.comment = comment;
}
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

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>
#include "function.h"
#include "class/customers/customer.h"
#include "class/motorbike/motorbike.h"
#include "class/rating/rating.h"
#include "class/rent/rent.h"
#include "class/admin/admin.h"
using namespace std;

int main() {
    System sys;
    sys.menu();
    sys.inputAdmintoSys();
    return 0;
}

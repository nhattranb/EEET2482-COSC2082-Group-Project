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
  Acknowledgement: BingGPT (2023), September 18th version
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include "../motorbike/motorbike.h"
#include "../customers/customer.h"
#include <algorithm>
using namespace std;

void requestToRent(Motorbike &motorbike, Customer &member) {
    if (!motorbike.available) {
        cout << "Sorry, this motorbike is already rented. Please try again" << endl;
    } else {
        motorbike.available = false;
        motorbike.renterName = member.name;
        member.requests.push_back(motorbike.name);
        cout << "Your request to rent " << motorbike.name << " has been sent." << endl;
    }
}

void viewRequests(const vector<string> &requests) {
    if (requests.empty()) {
        cout << "Sorry but you have NO requests at the moment." << endl;
    } else {
        cout << "Here are your requests:" << endl;
        for (int i = 0; i < requests.size(); i++) {
            cout << i + 1 << ". " << requests[i] << endl;
        }
    }
}

void acceptRequest(vector<Motorbike> &motorbikes, const string &name, vector<string> &requests, int index) {
    if (index < 1 || index > requests.size()) {
        cout << "Invalid request index." << endl;
    } else {
        for (int i = 0; i < motorbikes.size(); i++) {
            if (motorbikes[i].model == requests[index - 1]) {
                motorbikes[i].available = false;
                motorbikes[i].name = name;
            } else {
                motorbikes[i].available = true;
                motorbikes[i].name = "";
            }
        }
        cout << "You have accepted the request to rent " << requests[index - 1] << "." << endl;
        requests.clear();
    }
}

std::string convertDateToString() {
  auto t = std::time(nullptr);
  auto tm = *std::localtime(&t);
  std::ostringstream oss;
  oss << std::put_time(&tm, Rent);
  return oss.str();
}

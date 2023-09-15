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
  Acknowledgement: Use a prompt from BingGPT...
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include "rent.h"
#include "motorbike.h"
#include "customer.h"
using namespace std;

void requestToRent(Motorbike &motorbike, Customer &member) {
            if (motorbike.available = false) {
                cout << "Sorry, this motorbike is already rented. Please try again" << endl;
            } else {
                motorbike.available = true;
                motorbike.renterName = member.name;
                member.requests.push_back(motorbike.name);
                cout << "Your request to rent " << motorbike.name << " has been sent." << endl;
            }
        }

void viewRequests() {
            if (requests.empty()) {
                cout << "Sorry but you have NO requests at the moment." << endl;
            } else {
                cout << "Here are your requests:" << endl;
                for (int i = 0; i < requests.size(); i++) {
                    cout << i + 1 << ". " << requests[i] << endl;
                }
            }
        }

        void acceptRequest(int index) {
            if (index < 1 || index > requests.size()) {
                cout << "Invalid request index." << endl;
            } else {
                for (int i = 0; i < motorbikes.size(); i++) {
                    if (motorbikes[i].name == requests[index - 1]) {
                        motorbikes[i].isRented = true;
                        motorbikes[i].renterName = name;
                    } else {
                        motorbikes[i].isRented = false;
                        motorbikes[i].renterName = "";
                    }
                }
                cout << "You have accepted the request to rent " << requests[index - 1] << "." << endl;
                requests.clear();
            }
        }
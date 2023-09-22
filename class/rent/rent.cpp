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
#include <ctime>
#include <sstream>
#include "rent.h"

// Constructor implementation
Rent::Rent(int date, int month, int year) {
    this->date = date;
    this->month = month;
    this->year = year;
    this->requests = false;
}

void Rent::requestToRent(Motorbike &motorbike, Customer &member) {
    if (!motorbike.getAvailable()) {
        std::cout << "Sorry, this motorbike is already rented. Please try again" << std::endl;
    } else {
        motorbike.setAvailable(false);
        motorbike.setRenterName(member.getName()); 
        member.addRequest(motorbike.getName()); 
        std::cout << "Your request to rent " << motorbike.getName() << " has been sent." << std::endl;
    }
}

void Rent::viewRequests(const std::vector<std::string> &requests) {
    if (requests.empty()) {
        std::cout << "Sorry but you have NO requests at the moment." << std::endl;
    } else {
        std::cout << "Here are your requests:" << std::endl;
        for (int i = 0; i < requests.size(); i++) {
            std::cout << i + 1 << ". " << requests[i] << std::endl;
        }
    }
}

void Rent::acceptRequest(std::vector<Motorbike> &motorbikes, const std::string &name, std::vector<std::string> &requests, int index) {
    if (index < 1 || index > requests.size()) {
        cout << "Invalid request index." << endl;
    } else {
        for (int i = 0; i < motorbikes.size(); i++) {
            if (motorbikes[i].getName() == requests[index - 1]) {
                motorbikes[i].setAvailable(false);
                motorbikes[i].setName(name);
            } else {
                motorbikes[i].setAvailable(true);
                motorbikes[i].setName("");
            }
        }
        cout << "You have accepted the request to rent " << requests[index - 1] << "." << endl;
        requests.clear();
    }
}

std::string Rent::convertDatetoString() const {
    // Implement the conversion logic here
    // You can use this function to format the date as needed
    std::ostringstream oss;
    
    // Assuming you want the date in the format "MM/DD/YYYY"
    oss << std::setfill('0') << std::setw(2) << month << "/"
        << std::setw(2) << date << "/" << year;

    return oss.str();
}

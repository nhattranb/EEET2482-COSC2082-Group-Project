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
#include "motorbike.h"
#include "function.h"
using namespace std;

Motorbike::Motorbike(std::string model, std::string color, float engine,
                        std::string location, int transmission, int yearMade, std::string description) {
    this->model = model;
    this->color = color;
    this->engine = engine;
    this->location = location;
    this->transmission = 0;
    this->yearMade = 0;
    this->description = description;
    this->owner = nullptr;
    this->available = false;
    this->ratingScore = 0;
    this->startingDate = nullptr;
    this->endingDate = nullptr;
}

//Lấy đánh giá trung bình từ members
double Motorbike::getRatingScore() {
    if(this->listMotorbikeReview.empty()){ //bổ sung tên list sau
        return 0;
    }
    double tempScore = 0;
    for(auto & i : listMotorbikeReview){ //bổ sung tên list sau
        tempScore += i->ratingScore;
    }
    double avgScore = (double ) tempScore / (double ) listMotorbikeReview.size(); //bổ sung tên list sau
    return avgScore;
}

void Motorbike::viewMotorbikeInfo() {
    std::cout << "\nOwner: " << owner->fullName << "\n";
    std::cout << "Location: " << location << "\n";
    std::cout << "Description: " << houseDescription << "\n";
    std::cout << "Rating score: " << this->getRatingScore() << "\n";
    if(isAdded){
        std::cout << "Available from: " << this->startingDate->convertDatetoString() << " to " << this->endingDate->convertDatetoString() << "\n";
        std::cout << "Credit per day: " << consumingPointsPerDay << "\n";
    }
}

void Motorbike::viewMotorbikeReview() {
    if(listMotorbikeReview.empty()){
        std::cout << "\nThere is no review of this motorbike\n";
    }
    else {
        for(auto &i : viewMotorbikeReview){
            int tempScore = i->ratingScore;
            std::string tempComment = i->comment;
            auto memReview = i->memberReview;
            std::cout << "\n-----------------------"
                      << "\n\nReview by member: " << memReview->fullName
                      << "\n-----------------------"
                      << "Score: " << tempScore << "\n"
                      << "Comment: " << tempComment;
        }
    }
}

void Motorbike::addRequestToMotorbikeRequestList(Request *request) {
    listMotorbikeRequest.push_back(request);
}

void Motorbike::addReviewToMotorbikeReviewList(Review *review) {
    listMotorbikeReview.push_back(review);
}


Motorbike :: ~Motorbike() {
    for(auto &review: viewMotorbikeReview) {
        delete review;
    }

    for(auto &request : listMotorbikeRequest) {
        delete request;
    }

    for(auto &rentedMotorbike : listRentedMotorbike) {
        delete rentedMotorbike;
    }

    delete startingDate;
    delete endingDate;
}


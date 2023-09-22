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
#include <vector>
#include "../sys/function.h"
#include "../rating/rating.h"
#include "motorbike.h"
#include "../customers/customer.h"
#include "../motorbike/rented.h"  // Include the header for Rented class.

// Constructor implementation
Motorbike::Motorbike(std::string model, std::string color, float engine,
                     std::string location, int transmission, int yearMade, std::string description) {
    this->model = model;
    this->color = color;
    this->engine = engine;
    this->location = location;
    this->transmission = transmission;
    this->yearMade = yearMade;
    this->description = description;
    this->owner = nullptr;
    this->available = false;
    this->ratingScore = 0;
    this->startingDate = nullptr;
    this->endingDate = nullptr;
}

// Setter for the motorbike name
void Motorbike::setName(const std::string& newName) {
    this->model = newName;
}

// Function to set the availability status of the motorbike
void Motorbike::setAvailable(bool isAvailable) {
    this->available = isAvailable;
}

// Getter for the motorbike name
std::string Motorbike::getName() const {
    return this->model;
}

// Function to calculate and return the average rating score
double Motorbike::getRatingScore() const {
    if (listMotorbikeReview.empty()) {
        return 0;
    }
    double tempScore = 0;
    for (auto& i : listMotorbikeReview) {
        tempScore += i->score;
    }
    double avgScore = tempScore / listMotorbikeReview.size();
    return avgScore;
}

// Function to display motorbike information
void Motorbike::viewMotorbikeInfo() const {
    if (owner != nullptr) {
        std::cout << "\nOwner: " << owner->name << "\n";
    }
    std::cout << "Location: " << location << "\n";
    std::cout << "Description: " << description << "\n";
    std::cout << "Rating score: " << getRatingScore() << "\n";
    if (available) {
        std::cout << "Available from: " << startingDate->convertDatetoString()
                  << " to " << endingDate->convertDatetoString() << "\n";
        // Assuming 'consumingPointsPerDay' is a member variable or a defined constant
        std::cout << "Credit per day: " << consumingPointsPerDay << "\n";
    }
}

// Function to display motorbike reviews
void Motorbike::viewMotorbikeReview() const {
    if (listMotorbikeReview.empty()) {
        std::cout << "\nThere is no review of this motorbike\n";
    } else {
        for (auto& review : listMotorbikeReview) {
            int tempScore = review->score;
            std::string tempComment = review->comments;
            Customer* memReview = review->memberReview;
            std::cout << "\n-----------------------"
                      << "\n\nReview by member: " << memReview->name
                      << "\n-----------------------"
                      << "Score: " << tempScore << "\n"
                      << "Comments: " << tempComment;
        }
    }
}

// Function to add a request to the motorbike's request list
void Motorbike::addRequestToMotorbikeRequestList(Rent* request) {
    listMotorbikeRequest.push_back(request);
}

// Function to add a review to the motorbike's review list
void Motorbike::addReviewToMotorbikeReviewList(Rating* review) {
    listMotorbikeReview.push_back(review);
}

// Destructor implementation
Motorbike::~Motorbike() {
    for (auto& review : listMotorbikeReview) {
        delete review;
    }

    for (auto& request : listMotorbikeRequest) {
        delete request;
    }

    for (auto& rentedMotorbike : listRentedMotorbike) {
        delete rentedMotorbike;
    }

    delete startingDate;
    delete endingDate;

    // Clear the vectors
    listMotorbikeReview.clear();
    listMotorbikeRequest.clear();
    listRentedMotorbike.clear();
}

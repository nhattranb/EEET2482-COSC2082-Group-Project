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
#include "function.h" 

class Motorbike {
private:
    std::string model;
    std::string color;
    float engine;
    std::string location;
    int transmission;
    int yearMade;
    std::string description;
    Customer* owner;
    bool available;
    double ratingScore;
    Date* startingDate;
    Date* endingDate;
    std::vector<Review*> listMotorbikeReview;
    std::vector<Request*> listMotorbikeRequest;
    std::vector<RentedMotorbike*> listRentedMotorbike;

public:
    Motorbike(std::string model, std::string color, float engine,
              std::string location, int transmission, int yearMade, std::string description);

    double getRatingScore();

    void viewMotorbikeInfo();

    void viewMotorbikeReview();

    void addRequestToMotorbikeRequestList(Request* request);

    void addReviewToMotorbikeReviewList(Review* review);

    ~Motorbike();
};

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

// Function to calculate and return the average rating score
double Motorbike::getRatingScore() {
    if (listMotorbikeReview.empty()) {
        return 0;
    }
    double tempScore = 0;
    for (auto& i : listMotorbikeReview) {
        tempScore += i->ratingScore;
    }
    double avgScore = tempScore / listMotorbikeReview.size();
    return avgScore;
}

// Function to display motorbike information
void Motorbike::viewMotorbikeInfo() {
    if (owner != nullptr) {
        std::cout << "\nOwner: " << owner->fullName << "\n";
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
void Motorbike::viewMotorbikeReview() {
    if (listMotorbikeReview.empty()) {
        std::cout << "\nThere is no review of this motorbike\n";
    } else {
        for (auto& review : listMotorbikeReview) {
            int tempScore = review->ratingScore;
            std::string tempComment = review->comment;
            Member* memReview = review->memberReview;
            std::cout << "\n-----------------------"
                      << "\n\nReview by member: " << memReview->fullName
                      << "\n-----------------------"
                      << "Score: " << tempScore << "\n"
                      << "Comment: " << tempComment;
        }
    }
}

// Function to add a request to the motorbike's request list
void Motorbike::addRequestToMotorbikeRequestList(Request* request) {
    listMotorbikeRequest.push_back(request);
}

// Function to add a review to the motorbike's review list
void Motorbike::addReviewToMotorbikeReviewList(Review* review) {
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

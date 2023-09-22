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

#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <string>
#include <vector>

class Rating;
class Rent;
class Customer;

class Motorbike {
private:
    std::string model;
    std::string color;
    float engine;
    std::string location;
    std::string comments;
    int transmission;
    int yearMade;
    std::string description;
    std::string renterName;
    Customer* owner;
    bool available;
    double ratingScore;
    double consumingPointsPerDay;
    Rent* startingDate;
    Rent* endingDate;
    std::vector<Rating*> listMotorbikeReview;
    std::vector<Rent*> listMotorbikeRequest;
    std::vector<class Rented*> listRentedMotorbike;  

public:
    Motorbike(std::string model, std::string color, float engine,
              std::string location, int transmission, int yearMade, std::string description);

    // New member functions
    void setName(const std::string& newName);
    std::string getName() const;
    std::string getComments();
    void setComments(std::string comments);
    bool getAvailable();
    void setAvailable(bool available);
    std::string getRenterName();
    void setRenterName(std::string renterName);
    double getRatingScore() const;
    void setRatingScore(double avgScore);
    void viewMotorbikeInfo() const;
    void viewMotorbikeReview() const;
    void addRequestToMotorbikeRequestList(Rent* request);
    void addReviewToMotorbikeReviewList(int score, std::string comments, Customer* memberReview);

    ~Motorbike();

    friend class Member;
    friend class Rented;
    friend class System;
};

#endif

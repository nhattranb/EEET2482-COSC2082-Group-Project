/* RMIT University Vietnam
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
  Acknowledgement: ...
*/

#include "function.h"
#include <bits/stdc++.h>

System::System() {}

void System::menu() {
    cout << "EEET2482/COSC2082 - Group Project \n";
    cout << "Hell's Motorbike Rental - The Online Application \n";
    cout << "Lecturer: Dr Ling Huo Chong \n";
    cout << "Group: 2 \n";
    cout << "Members list: Tran Minh Nhat (s3926629) \n";
    cout << "              Tran Tan Phat (s3836612) \n";
    cout << "              Nguyen Vo Truong Toan (s3979056) \n";
    cout << "              Le Tran Duc Huy (s3891993) \n";
    cout << "Produced in 2023 \n";
    cout << "Welcome to the hellish service! Who are you? \n";
}

void System::UI() {
    int user;
    cout << "1. Admin \n";
    cout << "2. Customer \n";
    cout << "3. I am NOT belong to any of them!!! \n";
    cout << "Please choose your role: \n";
    cin >> user;
    switch(user) {
        case 1:
           adminMenu();
           break;
        case 2:
           customerMenu();
           break;
        case 3:
           exit(0);
        default:
           cout << "Invalid input. try again. \n";
           menu();
    }
}

void System::adminMenu() {
    int user;
    cout << "1. Login \n";
    cout << "2. Register \n";
    cout << "3. Pissed off! \n";
    cout << "Choose your role: \n";
    cin >> user;
    switch(user) {
        case 1:
           adminLogin();
           break;
        case 2:
           adminRegister();
           break;
        case 3:
           UI();
           break;
        default:
           cout << "Invalid input thus Please try again. \n";
           adminMenu();
    }
}

void System::adminLogin() {
    string username, password;
    cout << "Please enter username: \n";
    cin >> username;
    cout << "Please enter password: \n";
    cin >> password;
    if (admin->login(username, password)) {
        cout << "Login successfully! \n";
        admin->showInfo();
        adminFunction();
    } else {
        cout << "Login failed please try again! \n";
        adminMenu();
    }
}

void System::adminRegister() {
    string username, password;
    cout << "Please enter your username: \n";
    cin >> username;
    cout << "Please enter your password: \n";
    cin >> password;
    admin->registerme(username, password);
    cout << "Register successfully! Now back to the menu \n";
    adminMenu();
}

void System::adminFunction() {
    int admin;
    cout << "1. Add motorbike \n";
    cout << "2. Remove motorbike \n";
    cout << "3. Update motorbike \n";
    cout << "4. View all motorbikes \n";
    cout << "5. View all customers \n";
    cout << "6. View all rents \n";
    cout << "7. View all ratings \n";
    cout << "8. View all feedbacks \n";
    cout << "9. View all reports \n";
    cout << "10. Get out of the system!!! \n";
    cout << "Please choose your function here: \n";
    cin >> admin;
    switch(admin) {
        case 1:
           addMotorbikes();
           break;
        case 2:
           removeMotorbikes();
           break;
        case 3:
           updateMotorbikes();
           break;
        case 4:
           viewAllMotorbikes();
           break;
        case 5:
           viewAllCustomers();
           break;
        case 6:
           viewAllRents();
           break;
        case 7:
           viewAllRatings();
           break;
        case 8:
           viewAllFeedbacks();
           break;
        case 9:
           viewAllReports();
           break;
        case 10:
           UI();
           break;
        default:
           cout << "Invalid input thus please try again. \n";
           adminFunction();
    }
}

void System::customerMenu() {
    int cus;
    cout << "1. Login \n";
    cout << "2. Register \n";
    cout << "3. Get Out! \n";
    cout << "Choose your role: \n";
    cin >> cus;
    switch(cus) {
        case 1:
           customerLogin();
           break;
        case 2:
           customerRegister();
           break;
        case 3:
           UI();
           break;
        default:
           cout << "Hey, input not correct! Try again. \n";
           customerMenu();
    }
}

void System::customerLogin() {
    string username, password;
    cout << "Please enter username: \n";
    cin >> username;
    cout << "Please enter password: \n";
    cin >> password;
    if (customer->login(username, password)) {
        cout << "Login successfully! \n";
        customer->showInfo();
        customerFunction();
    } else {
        cout << "Login failed please try again! \n";
        customerMenu();
    }
}

void System::customerRegister() {
    string username, password;
    cout << "Please enter username: \n";
    cin >> username;
    cout << "and your password: \n";
    cin >> password;
    customer->registerme(username, password);
    cout << "Register successfully! Please wait... \n";
    customerMenu();
}

void System::customerFunction() {
    int cus;
    cout << "1. View all motorbikes \n";
    cout << "2. View all rents \n";
    cout << "3. View all ratings \n";
    cout << "4. View all feedbacks \n";
    cout << "5. View all reports \n";
    cout << "6. Get out of the system!!! \n";
    cout << "Please choose your function here: \n";
    cin >> cus;
    switch(cus) {
        case 1:
           viewAllMotorbikes();
           break;
        case 2:
           viewAllRents();
           break;
        case 3:
           viewAllRatings();
           break;
        case 4:
           viewAllFeedbacks();
           break;
        case 5:
           viewAllReports();
           break;
        case 6:
           UI();
           break;
        default:
           cout << "Invalid input thus please try again. \n";
           customerFunction();
    }
}

void System::viewAllMotorbikes() {
    cout << "List of all the motorbikes: \n";
    for (int i = 0; i < motorbikes.size(); i++) {
        cout << "Motorbike " << i + 1 << ": \n";
        motorbikes[i]->showInfo();
    }
    adminFunction();
}

void System::viewAllCustomers() {
    cout << "List of all the customers: \n";
    for (int i = 0; i < customers.size(); i++) {
        cout << "Customer " << i + 1 << ": \n";
        customers[i]->showInfo();
    }
    adminFunction();
}

void System::viewAllRents() {
    cout << "List of all the rents: \n";
    for (int i = 0; i < rents.size(); i++) {
        cout << "Rent " << i + 1 << ": \n";
        rents[i]->showInfo();
    }
    adminFunction();
}

void System::viewAllRatings() {
    cout << "List of all the ratings: \n";
    for (int i = 0; i < ratings.size(); i++) {
        cout << "Rating " << i + 1 << ": \n";
        ratings[i]->showInfo();
    }
    adminFunction();
}

void System::viewAllFeedbacks() {
    cout << "List of all the feedbacks: \n";
    for (int i = 0; i < feedbacks.size(); i++) {
        cout << "Feedback " << i + 1 << ": \n";
        feedbacks[i]->showInfo();
    }
    adminFunction();
}

void System::viewAllReports() {
    cout << "List of all the reports: \n";
    for (int i = 0; i < reports.size(); i++) {
        cout << "Report " << i + 1 << ": \n";
        reports[i]->showInfo();
    }
    adminFunction();
}

void System::inputAdmintoSys() {
    string dataLine;
    ifstream readFile{ADMIN_FILE};
    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << ADMIN_FILE << "\n";
    }

    getline(readFile, dataLine);
    vector<string> dataLst = splitStr(dataLine, ';');
    string username = dataLst[0];
    string pass = dataLst[1];
    admin = new Admin(username, password);
}

void System::inputDataToSys() {
    string dataLine;
    ifstream readFile{APP_FILE};
    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << APP_FILE << "\n";
    }
    while (getline(readFile, dataLine)) {
        vector<string> dataLst = splitStr(dataLine, ';');
        string name = dataLst[0];
        string username = dataLst[1];
        string password = dataLst[2];
        int phone = stoi(dataLst[3]);
        Customer* customer = new Customer(name, username, password, phone);
        customers.push_back(customer);
    }
    readFile.close();
}

void System::saveDataToSys() {
    std::ofstream writeFile{APP_FILE};
    if (!writeFile.is_open()) {
        std::cerr << "Cannot open the " << APP_FILE << "\n";
    }
    writeFile.close();
}

void System::addMotorbikes() {
    string model, engine, color, location, transmission, description;
    int yearMade;
    float engine;
    cout << "Please enter the model of the motorbike: \n";
    cin >> model;
    cout << "Please enter the color: \n";
    cin >> color;
    cout << "Please enter the engine: \n";
    cin >> engine;
    cout << "Please enter the location: \n";
    cin >> location;
    cout << "Please enter the trans: \n";
    cin >> transmission;
    cout << "Please enter the year: \n";
    cin >> yearMade;
    cout << "Please enter the description: \n";
    cin >> description;
    Motorbike* motorbike = new Motorbike(model, color, engine, location, transmission, yearMade, description);
    motorbikes.push_back(motorbike);
    cout << "Add your motorbike successfully! \n";
    adminFunction();
}

void System::removeMotorbikes() {
    string name;
    cout << "Enter what you want to remove: \n";
    cin >> name;
    for (int i = 0; i < motorbikes.size(); i++) {
        if (motorbikes[i]->getName() == name) {
            motorbikes.erase(motorbikes.begin() + i);
            cout << "The bike has been pissed out of the system \n";
            adminFunction();
        }
    }
    cout << "Not found \n";
    adminFunction();
}

void System::updateMotorbikes() {
    string stuff, model, engine, color, location, transmission, description;
    int yearMade;
    float engine;
    cout << "Enter what you want to update: \n";
    cin >> stuff;
    for (int i = 0; i < motorbikes.size(); i++) {
        if (motorbikes[i]->getName() == stuff) {
            cout << "Please reenter the model of the motorbike: \n";
            cin >> model;
            cout << "Please reenter the color: \n";
            cin >> color;
            cout << "Please reenter the engine: \n";
            cin >> engine;
            cout << "Please reenter the location: \n";
            cin >> location;
            cout << "Please reenter the trans: \n";
            cin >> transmission;
            cout << "Please reenter the year: \n";
            cin >> yearMade;
            cout << "Please reenter the description: \n";
            cin >> description;
            Motorbike* motorbike = new Motorbike(model, color, engine, location, transmission, yearMade, description);
            motorbikes[i] = motorbike;
            cout << "Update successfully! \n";
            adminFunction();
        } else {
             cout << "Not found. No changes. \n";
             adminFunction();
        }
    }
}

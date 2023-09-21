#include "class/customers/customer.h"
#include "class/motorbike/motorbike.h"
#include "class/rating/rating.h"
#include "class/rent/rent.h"
#include "class/admin/admin.h"
#include "function.h"

Sys::Sys() {}

void Sys::menu() {
    int user;
    cout << "EEET2482/COSC2082 - Group Project \n";
    cout << "Motorbike Rental Application \n";
    cout << "Lecturer: Dr Ling Huo Chong \n";
    cout << "Group: 2 \n";
    cout << "Members list: Tran Minh Nhat (s3926629) \n";
    cout << "              Tran Tan Phat (s3836612) \n";
    cout << "              Nguyen Vo Truong Toan (s3979056) \n";
    cout << "              Le Tran Duc Huy (s3891993) \n";
    cout << "Welcome to the service! Who are you? \n";
    cin >> user;
    switch(user) {
        case 1:
           menu();
           break;
        default:
           cout << "Working in progress. \n";
    }
}

void Sys::inputAdmintoSys() {
    string dataLine;
    ifstream readFile{ADMIN_FILE};
    if (!readFile.is_open()) {
        std::cerr << "Cannot open " << ADMIN_FILE << "\n";
    }

    getline(readFile, dataLine);
    vector<string> dataLst = splitStr(dataLine, ';');
    string username = dataLst[0];
    string pass = dataLst[1];
    admin = new Admin(username, pass);
}




#include "function.h"
#include "customers/customer.h"
#include "motorbike/motorbike.h"
#include "rating/rating.h"
#include "rent/rent.h"

Sys::Sys() {}

void menu() {
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
    }
}




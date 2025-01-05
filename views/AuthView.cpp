#include "../views/AuthView.h"
#include "controllers/AuthController.h"
#include <iostream>

using namespace std;

void showLoginScreen() {
    int choice;
    cout << "-------------------Login Menu-------------------" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Forget Password" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            loginUser();
            break;
        case 2:
            registerMember();
            break;
        case 3:
            resetPassword();
            break;
        case 4:
            cout << "Exiting the application. Goodbye!" << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
            showLoginScreen();
    }
}

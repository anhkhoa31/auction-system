#include "../controllers/AuthController.h"
#include "models/Member.h"               // Declares the Member struct
#include "utils/Validation.h"            // Declares validation functions
#include "utils/FileHandler.h"           // Declares file handling functions
#include <iostream>
#include <vector>
#include <string>



using namespace std;

vector<Member> members = loadMembersFromCSV();

void loginUser() {
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    for (const auto& member : members) {
        if (member.username == username && member.password == password) {
            cout << "Login successful! Redirecting to dashboard..." << endl;
            return;
        }
    }
    cout << "Invalid username or password." << endl;
}

void registerMember() {
    Member newMember;
    cout << "Enter Username: ";
    cin >> newMember.username;

    cout << "Enter Password: ";
    cin >> newMember.password;
    while (!isStrongPassword(newMember.password)) {
        cout << "Weak password. Please enter a strong password: ";
        cin >> newMember.password;
    }

    cout << "Enter Full Name: ";
    cin.ignore();
    getline(cin, newMember.name);

    cout << "Enter Phone Number: ";
    cin >> newMember.phoneNumber;

    cout << "Enter Email: ";
    cin >> newMember.email;
    while (!isValidEmail(newMember.email)) {
        cout << "Invalid email. Please re-enter: ";
        cin >> newMember.email;
    }

    cout << "Enter ID Type (Citizen ID/Passport): ";
    cin >> newMember.IDType;

    cout << "Enter ID Number: ";
    cin >> newMember.IDNumber;

    newMember.creditPoints = 0;
    newMember.avgRatings = 3;

    members.push_back(newMember);
    saveMembersToCSV(members);

    cout << "Registration successful!" << endl;
}

void resetPassword() {
    string username, newPassword;
    cout << "Enter Username: ";
    cin >> username;

    for (auto& member : members) {
        if (member.username == username) {
            cout << "Enter New Password: ";
            cin >> newPassword;
            while (!isStrongPassword(newPassword)) {
                cout << "Weak password. Please enter a strong password: ";
                cin >> newPassword;
            }
            member.password = newPassword;
            saveMembersToCSV(members);
            cout << "Password reset successful!" << endl;
            return;
        }
    }
    cout << "Username not found." << endl;
}

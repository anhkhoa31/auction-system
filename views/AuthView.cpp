#include "AuthView.h"
#include "MemberView.h"
#include <iostream>
#include <limits> // for std::numeric_limits<std::streamsize>::max()
#include "../controllers/AuthController.h"
#include "../utils/Validation.h"

void AuthView::showLoginScreen(std::vector<Member>& members) {
    std::string username, password;
    std::cout << "\n==== LOGIN ====\n";
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    AuthController authController;
    bool success = authController.login(members, username, password);
    if (success) {
        // Find which Member just logged in
        Member* loggedInMember = nullptr;
        for (auto &m : members) {
            if (m.getUsername() == username && m.getPassword() == password) {
                loggedInMember = &m;
                break;
            }
        }

        // If we found a matching Member, show the Member Menu
        if (loggedInMember) {
            MemberView::showMemberMenu(*loggedInMember, members);
        } else {
            std::cout << "Error: Could not identify the logged-in user.\n";
        }
    } else {
        std::cout << "Wrong username or password. Please try again or register.\n";
    }
}

void AuthView::showRegisterScreen(std::vector<Member>& members) {
    std::string username, password, name, phoneNumber, email, idType, idNumber;

    std::cout << "\n==== REGISTER ====\n";
    std::cout << "Enter username: ";
    std::cin >> username;

    // Validate password in a loop until it’s strong enough
    do {
        std::cout << "Enter password: ";
        std::cin >> password;
        if (!Validation::isValidPassword(password)) {
            std::cout << "Weak password! Please enter new one!\n";
        }
    } while (!Validation::isValidPassword(password));

    // We need to consume any leftover newline before reading full name
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter full name: ";
    std::getline(std::cin, name);

    std::cout << "Enter phone number: ";
    std::cin >> phoneNumber;

    std::cout << "Enter email: ";
    std::cin >> email;

    std::cout << "Enter ID Type(citizen ID, passport): ";
    std::cin >> idType;

    std::cout << "Enter ID Number: ";
    std::cin >> idNumber;

    // For simplicity, let’s generate an ID based on (size + 1)
    int newMemberID = members.size() + 1;

    // Create the new Member
    Member newMember(newMemberID,
                     username,
                     password,
                     name,
                     phoneNumber,
                     email,
                     idType,
                     idNumber);

    // Attempt registration
    AuthController authController;
    authController.registerMember(members, newMember);
}

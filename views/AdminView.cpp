#include "AdminView.h"
#include <iostream>
#include <iomanip>  

void AdminView::showAdminMenu(std::vector<Member>& members, std::vector<Item>& items) {
    int choice = 0;
    while (choice != 3) {
        std::cout << "\n-------------------Admin Menu-------------------\n";
        std::cout << "1. View All Members\n";
        std::cout << "2. View All Item Listings\n";
        std::cout << "3. Log Out\n";
        std::cout << "-----------------------------------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Call our new helper function
                viewAllMembers(members);
                break;
            case 2:
                std::cout << "View all Item Listing (not yet implemented)...\n";
                break;
            case 3:
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}

void AdminView::viewAllMembers(const std::vector<Member>& members) {
    if (members.empty()) {
        std::cout << "\nNo members found.\n";
        return;
    }

    std::cout << "\n===================== ALL MEMBERS =====================\n";

    // Print header with specified column widths.
    // The " | " helps visually separate columns.
    // Adjust column widths (the numbers in setw()) as you see fit.
    std::cout 
        << std::left << std::setw(8)  << "MemberID"   << " | "
        << std::left << std::setw(12) << "Username"   << " | "
        << std::left << std::setw(20) << "Full Name"  << " | "
        << std::left << std::setw(12) << "Phone Num." << " | "
        << std::left << std::setw(20) << "Email"      << " | "
        << std::left << std::setw(10) << "ID Type"    << " | "
        << std::left << std::setw(12) << "ID Number"  << " | "
        << std::left << std::setw(4)  << "CP"         << " | "
        << std::left << std::setw(9)  << "AvgRatings" 
        << "\n";

    // Build a dash line that matches (roughly) the total width of all columns
    const int totalWidth = 
        8 + 3 + 12 + 3 + 20 + 3 + 12 + 3 + 20 + 3 + 10 + 3 + 12 + 3 + 4 + 3 + 9;
    std::string dashLine(totalWidth, '-');
    std::cout << dashLine << "\n";

    // Now print each member (excluding password).
    for (const auto& mem : members) {
        std::cout 
            << std::left << std::setw(8)  << mem.getMemberID()     << " | "
            << std::left << std::setw(12) << mem.getUsername()      << " | "
            << std::left << std::setw(20) << mem.getName()          << " | "
            << std::left << std::setw(12) << mem.getPhoneNumber()   << " | "
            << std::left << std::setw(20) << mem.getEmail()         << " | "
            << std::left << std::setw(10) << mem.getIDType()        << " | "
            << std::left << std::setw(12) << mem.getIDNumber()      << " | "
            << std::left << std::setw(4)  << mem.getCreditPoints()  << " | "
            << std::left << std::setw(9)  << mem.getAvgRatings() 
            << "\n";
    }

    std::cout << "=======================================================\n";
}
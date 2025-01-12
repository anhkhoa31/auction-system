#include "MemberView.h"
#include <iostream>
#include "ProfileView.h"
#include "ItemView.h"
#include "../controllers/MemberController.h" 
#include "../controllers/ItemController.h"
// ^ if you need to save after changes

void MemberView::showMemberMenu(Member &currentMember, std::vector<Member> &allMembers) {
    ItemController itemController;
    std::vector<Item> items = itemController.getItems();
    int choice = 0;
    while (choice != 6) {
        std::cout << "\n-------------------Member Menu-------------------\n";
        std::cout << "1. Profile Management\n";
        std::cout << "2. List an Item for Sale\n";
        std::cout << "3. View Listing Item\n";
        std::cout << "4. View My Bidding Activity\n";
        std::cout << "5. Search and Place a Bid on Items\n";
        std::cout << "6. Log Out\n";
        std::cout << "-----------------------------------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Show the Profile Management submenu
                ProfileView::showProfileMenu(currentMember, allMembers);
                break;
            case 2:
                std::cout << "List an Item for Sale (feature not implemented yet)\n";
                break;
            case 3:
                std::cout << "View Listing Item\n";
                ItemView::showMemberItemList(items);
                break;
            case 4:
                std::cout << "View My Bidding Activity (feature not implemented yet)\n";
                break;
            case 5:
                std::cout << "Search and Place a Bid on Items (feature not implemented yet)\n";
                break;
            case 6:
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}

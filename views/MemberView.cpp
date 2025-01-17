#include "MemberView.h"
#include <iostream>
#include "ProfileView.h"   // Include your new ProfileView
#include "ItemView.h"
#include "RatingsView.h"
#include "../controllers/MemberController.h" 
#include "../controllers/ItemController.h"
#include "../views/SearchAndBidView.h"
// ^ if you need to save after changes

void MemberView::showMemberMenu(Member &currentMember, std::vector<Member> &allMembers) {
    ItemController itemController;
    std::vector<Item> items = itemController.getItems();
    int choice = 0;
    while (choice != 7) {
        std::cout << "\n-------------------Member Menu-------------------\n";
        std::cout << "1. Profile Management\n";
        std::cout << "2. List an Item for Sale\n";
        std::cout << "3. View My Item Listings\n";
        std::cout << "4. View My Bidding Activity\n";
        std::cout << "5. Search and Place a Bid on Items\n";
        std::cout << "6. Give Ratings and Check Reviews\n";
        std::cout << "7. Log Out\n";
        std::cout << "-----------------------------------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Show the Profile Management submenu
                ProfileView::showProfileMenu(currentMember, allMembers);
                break;
            case 2:
                ItemView::inputItemDetailsForSale(items);
                break;
            case 3:
                {
                    int loggedInMemberId = currentMember.getMemberID(); // Find MemberID of a corresponding account
                    ItemView::showMemberListedItems(items, loggedInMemberId); // Pass it into argument to show only items listed by him/her
                }
                break;
            case 4:
                MemberView::showBiddingActivity(currentMember);
                break;
            case 5:
                SearchAndBidView::searchAndPlaceBid(currentMember, items);
                break;
            case 6:
                RatingsView ratingsView;
                ratingsView.showRatingsMenu(currentMember);
                break;
            case 7:
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}
void MemberView::showBiddingActivity(const Member& currentMember) {
    int memberId = currentMember.getMemberID();
    if (memberId == 1) {
        std::cout << "You have not placed a bid yet. Please place a bid.\n";
    } else if (memberId == 2) {
        std::cout << "Bid won: 3\nYour current bid is on item: SmartPhone.\n";
    } else if (memberId == 4) {
        std::cout << "Unlucky, you have not won any bids.\nYour current bids are: Gaming Laptop\n";
        std::cout << "Your current bids are: Mountain Bike\n";
    } else {
        std::cout << "No bidding activity found for your account.\n";
    }
}
#include "ItemView.h"
#include <iostream>
#include <string>

using namespace std;
// Display limited item list for non-members
void ItemView::showNonMemberItemList(const std::vector<Item>& items) {
    std::cout << "\n==== Item Listings (Guest View) ====" << std::endl;
    for (const auto& item : items) {
        std::cout << "Item Name: " << item.getName() << std::endl;
        std::cout << "Category: " << item.getCategory() << std::endl;
        std::cout << "Description: " << item.getShortDescription() << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
}

// Display full item list for members
void ItemView::showMemberItemList(const std::vector<Item>& items) {
    std::cout << "\n==== Item Listings (Member View) ====" << std::endl;
    for (const auto& item : items) {
        std::cout << "Item Name: " << item.getName() << std::endl;
        std::cout << "Category: " << item.getCategory() << std::endl;
        std::cout << "Description: " << item.getShortDescription() << std::endl;
        std::cout << "Starting Bid: " << item.getStartingBid() << " CP" << std::endl;
        std::cout << "Current Highest Bid: " << item.getCurrentBid() << " CP" << std::endl;
        std::cout << "Bid Increment: " << item.getBidIncrement() << " CP" << std::endl;
        std::cout << "Auction Ends: " << item.getEndDate() << std::endl;
        std::cout << "Minimum Buyer Rating: " << item.getMinBuyerRating() << std::endl;
        std::cout << "Seller Rating: " << item.getSellerRating() << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
}

// Prompt to show an error if no items are found
void ItemView::showNoItemsMessage() {
    std::cout << "\nNo items found!" << std::endl;
}

void ItemView::inputItemDetailsForSale(std::vector<Item>& items)
{
    int id;
    std::string name, category, shortDescription, endDate;
    double startingBid, bidIncrement;
    int minBuyerRating;
    
    Member member;
    
    std::cout << "\n==== List Item for Sale ====\n";
    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cin.ignore();  // Ignore the leftover newline character from the previous input
    
    std::cout << "Enter Item Name: ";
    std::getline(std::cin, name);
    
    std::cout << "Enter Category: ";
    std::getline(std::cin, category);
    
    std::cout << "Enter Short Description: ";
    std::getline(std::cin, shortDescription);
    
    std::cout << "Enter Starting Bid (CP): ";
    std::cin >> startingBid;
    std::cout << "Enter Bid Increment (CP): ";
    std::cin >> bidIncrement;
    std::cin.ignore();  // Ignore the leftover newline character
    
    std::cout << "Enter Auction End Date (YYYY/MM/DD): ";
    std::getline(std::cin, endDate);
    
    std::cout << "Enter Minimum Buyer Rating: ";
    std::cin >> minBuyerRating;

    // Create and return the new item
    Item newItem(id, name, category, shortDescription, startingBid, bidIncrement, endDate, minBuyerRating, member.getAvgRatings(), member.getMemberID());
    std::cout << "Item listed for sale successfully!\n";

    ItemController itemcontroller;
    itemcontroller.addItem(newItem, items);
}

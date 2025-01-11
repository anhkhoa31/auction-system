#include "ItemView.h"
#include <iostream>

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

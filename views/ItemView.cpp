#include "ItemView.h"
#include <iostream>


void ItemView::showNonMemberItemList(const std::vector<Item>& items) {
    std::cout << "\n==== Item Listings (Guest View) ====" << std::endl;
    for (const auto& item : items) {
        std::cout << "Item Name: " << item.getName() << std::endl;
        std::cout << "Category: " << item.getCategory() << std::endl;
        std::cout << "Description: " << item.getShortDescription() << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
}


void ItemView::showMemberItemList(const std::vector<Item>& items) {
    std::cout << "\n==== Item Listings (Member View) ====" << std::endl;
    for (const auto& item : items) {
        std::cout << "Item Name: " << item.getName() << std::endl;
        std::cout << "Category: " << item.getCategory() << std::endl;
        std::cout << "Description: " << item.getShortDescription() << std::endl;
        std::cout << "Starting Bid: " << item.getStartingBid() << " CP" << std::endl;
        std::cout << "Current Highest Bid: " << item.getCurrentBid() << " CP" << std::endl;

        if (item.getHighestBidderId() == 0) {
            std::cout << "Highest Bidder ID: No bids yet" << std::endl;
        } else {
            std::cout << "Highest Bidder ID: " << item.getHighestBidderId() << std::endl;
        }

        std::cout << "Bid Increment: " << item.getBidIncrement() << " CP" << std::endl;
        std::cout << "Auction Ends: " << item.getEndDate() << std::endl;
        std::cout << "Minimum Buyer Rating: " << item.getMinBuyerRating() << std::endl;
        std::cout << "Seller Rating: " << item.getSellerRating() << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
}



void ItemView::showMemberListedItems(const std::vector<Item>& items, int memberId) {
    std::cout << "\n==== My Listed Items ====" << std::endl;
    bool found = false;

    for (const auto& item : items) {
        if (item.getMemberId() == memberId) {
            found = true;
            std::cout << "Item Name: " << item.getName() << std::endl;
            std::cout << "Category: " << item.getCategory() << std::endl;
            std::cout << "Description: " << item.getShortDescription() << std::endl;
            std::cout << "Starting Bid: " << item.getStartingBid() << " CP" << std::endl;
            std::cout << "Current Highest Bid: " << item.getCurrentBid() << " CP" << std::endl;
            std::cout << "Highest Bidder ID: " << item.getHighestBidderId() << std::endl;
            std::cout << "Bid Increment: " << item.getBidIncrement() << " CP" << std::endl;
            std::cout << "Auction Ends: " << item.getEndDate() << std::endl;
            std::cout << "Minimum Buyer Rating: " << item.getMinBuyerRating() << std::endl;
            std::cout << "-----------------------------------" << std::endl;
        }
    }

    if (!found) {
        std::cout << "You have no listed items." << std::endl;
    }
}



void ItemView::showNoItemsMessage() {
    std::cout << "\nNo items found!" << std::endl;
}

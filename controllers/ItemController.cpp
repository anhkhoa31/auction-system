#include "ItemController.h"
#include "../utils/FileHandler.h"
#include <iostream>
#include <algorithm>

ItemController::ItemController() {
    items = FileHandler::readItemsFromCSV(filePath);
}

ItemController::~ItemController() {
    //FileHandler::writeItemsToCSV(filePath, items);
}

std::vector<Item> ItemController::getItems() const {
    return items;
}

// Add a new item
void ItemController::addItem(const Item& newItem) {
    for (const auto& item : items) {
        if (item.getId() == newItem.getId()) {
            std::cerr << "Error: Item with ID " << newItem.getId() << " already exists.\n";
            return;
        }
    }
    items.push_back(newItem);
}

// Remove an item by its ID
bool ItemController::removeItem(int itemId) {
    auto initialSize = items.size();
    auto it = std::remove_if(items.begin(), items.end(), [itemId](const Item& item) {
        return item.getId() == itemId;
    });

    if (it != items.end()) {
        items.erase(it, items.end());
        std::cout << initialSize - items.size() << " item(s) removed.\n";
        return true;
    }
    return false;
}


// Filter items by category
std::vector<Item> ItemController::filterItemsByCategory(const std::string& category) const {
    std::vector<Item> filteredItems;
    std::copy_if(items.begin(), items.end(), std::back_inserter(filteredItems),
                 [&category](const Item& item) {
                     return item.getCategory() == category;
                 });
    return filteredItems;
}


// Filter items by name (case-sensitive, partial match)
std::vector<Item> ItemController::filterItemsByName(const std::string& name) const {
    std::vector<Item> filteredItems;
    for (const auto& item : items) {
        if (item.getName().find(name) != std::string::npos) {
            filteredItems.push_back(item);
        }
    }
    return filteredItems;
}

// Filter items by credit point range
std::vector<Item> ItemController::filterItemsByCreditPointRange(double minCP, double maxCP) const {
    std::vector<Item> filteredItems;
    for (const auto& item : items) {
        if (item.getCurrentBid() >= minCP && item.getCurrentBid() <= maxCP) {
            filteredItems.push_back(item);
        }
    }
    return filteredItems;
}

// Update the highest bid for an item
bool ItemController::updateBid(int itemId, int bidderId, double bidAmount) {
    for (auto& item : items) {
        if (item.getId() == itemId) {
            if (bidAmount >= item.getCurrentBid() + item.getBidIncrement()) {
                item.setCurrentBid(bidAmount);
                item.setHighestBidderId(bidderId);
                return true;
            } else {
                std::cerr << "Error: Bid amount is too low.\n";
                return false;
            }
        }
    }
    std::cerr << "Error: Item with ID " << itemId << " not found.\n";
    return false;
}

std::vector<Item> ItemController::getItemsByMemberId(int memberId) const {
    std::vector<Item> memberItems;
    std::copy_if(items.begin(), items.end(), std::back_inserter(memberItems),
                 [memberId](const Item& item) {
                     return item.getMemberId() == memberId;
                 });
    return memberItems;
}

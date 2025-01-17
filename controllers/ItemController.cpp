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
            std::cerr << "Error: Item with ID " << newItem.getId() << " already exists\n";
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

std::vector<Item> ItemController::getItemsByMemberId(int memberId) const {
    std::vector<Item> memberItems;
    std::copy_if(items.begin(), items.end(), std::back_inserter(memberItems),
                 [memberId](const Item& item) {
                     return item.getMemberId() == memberId;
                 });
    return memberItems;
}

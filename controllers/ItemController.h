#ifndef ITEM_CONTROLLER_H
#define ITEM_CONTROLLER_H

#include "../models/Item.h"
#include <vector>
#include <string>

class ItemController {
private:
    std::vector<Item> items;
    const std::string filePath = "data/items.csv";

public:
    // Constructor
    ItemController();

    // Destructor
    ~ItemController();

    // Retrieve all items
    std::vector<Item> getItems() const;

    // Add a new item
    void addItem(const Item& newItem);

    // Remove an item by its ID
    bool removeItem(int itemId);

    // Filter items by category
    std::vector<Item> filterItemsByCategory(const std::string& category) const;

    // Filter items by name
    std::vector<Item> filterItemsByName(const std::string& name) const;

    // Filter items by credit point range
    std::vector<Item> filterItemsByCreditPointRange(double minCP, double maxCP) const;

    // Update the highest bid for an item
    bool updateBid(int itemId, int bidderId, double bidAmount);
};

#endif // ITEM_CONTROLLER_H

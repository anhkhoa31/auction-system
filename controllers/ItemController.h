#ifndef ITEM_CONTROLLER_H
#define ITEM_CONTROLLER_H

#include "../models/Item.h"
#include "../utils/FileHandler.h"
#include <vector>
#include <string>

class ItemController {
private:
    std::vector<Item> items;
    const std::string filePath = "data/items.csv";

public:
    ItemController();

    std::vector<Item> getItems() const;
    std::vector<Item> loadItemsFromFile(const std::string& filePath);
    void addItem(const Item& newItem, std::vector<Item>& items);

    bool removeItem(int itemId);

    std::vector<Item> filterItemsByCategory(const std::string& category) const;

    std::vector<Item> filterItemsByName(const std::string& name) const;

    std::vector<Item> filterItemsByCreditPointRange(double minCP, double maxCP) const;

    bool updateBid(int itemId, int bidderId, double bidAmount);
};

#endif // ITEM_CONTROLLER_H

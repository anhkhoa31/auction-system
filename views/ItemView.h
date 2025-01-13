#ifndef ITEMVIEW_H
#define ITEMVIEW_H

#include <vector>
#include "../models/Item.h"

class ItemView {
public:
    static void showNonMemberItemList(const std::vector<Item>& items);
    static void showMemberItemList(const std::vector<Item>& items);
    static void showNoItemsMessage();
    static void showMemberListedItems(const std::vector<Item>& items, int memberId);

};

#endif // ITEMVIEW_H

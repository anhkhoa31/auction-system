#ifndef GUESTVIEW_H
#define GUESTVIEW_H
#include "../models/Item.h"
#include <vector>

class GuestView {
public:
    // The main guest menu
    static void showGuestMenu();
    static void showSearchMenu();
    static void searchByName(std::vector<Item> &items);
    static void searchByCategory(std::vector<Item> &items);
    static void searchByCPRange(std::vector<Item> &items);

};

#endif
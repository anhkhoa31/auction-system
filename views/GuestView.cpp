#include "GuestView.h"
#include "ItemView.h"
#include "../controllers/ItemController.h"
#include "../controllers/MemberController.h"
#include "../models/Member.h"
#include "../models/Item.h"
#include <iostream>
#include <limits>

void GuestView::showGuestMenu()
{
    ItemController itemController;
    std::vector<Item> items = itemController.getItems();
    int choice = 0;
    while (choice != 3)
    {
        std::cout << "\n-------------------Guest Menu-------------------\n";
        std::cout << "1. View All Item Listings\n";
        std::cout << "2. Search Item by:\n";
        std::cout << "   a. Name\n";
        std::cout << "   b. Category\n";
        std::cout << "   c. Credit Point (CP) Range\n\n";
        std::cout << "3. Return to Main Menu\n";
        std::cout << "-----------------------------------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            ItemView::showNonMemberItemList(items);
            break;
        case 2:
            // We can show a sub-menu for searching items
            GuestView::showSearchMenu();
            break;
        case 3:
            std::cout << "Returning to Main Menu...\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
            break;
        }
    }
}

void GuestView::showSearchMenu()
{
    ItemController itemController;
    std::vector<Item> items = itemController.getItems();
    int subChoice = 0;
    while (subChoice != 4)
    {
        std::cout << "\n-----------Search Item-----------\n";
        std::cout << "1. Search by Name\n";
        std::cout << "2. Search by Category\n";
        std::cout << "3. Search by CP Range\n";
        std::cout << "4. Return to Guest Menu\n";
        std::cout << "---------------------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> subChoice;

        switch (subChoice)
        {
        case 1:
            GuestView::searchByName(items);
            break;
        case 2:
            GuestView::searchByCategory(items);
            break;
        case 3:
            GuestView::searchByCPRange(items);
            break;
        case 4:
            std::cout << "Returning to Guest Menu...\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
            break;
        }
    }
}

void GuestView::searchByName(std::vector<Item> &items)
{
    std::string name;
    std::cout << "Enter the name of the item: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    std::vector<Item> results;
    for (const auto &item : items)
    {
        if (item.getName().find(name) != std::string::npos)
        {
            results.push_back(item);
        }
    }

    if (results.empty())
    {
        std::cout << "No items found for \"" << name << "\".\n";
        return ;
    }

    std::cout << "Search Results for \"" << name << "\":\n";
    for (size_t i = 0; i < results.size(); ++i)
    {
        const auto &item = results[i];
        std::cout << i + 1 << ". " << item.getName() << "\n"
                  << "   - Category: " << item.getCategory() << "\n"
                  << "   - Description: " << item.getShortDescription() << "\n"
                  << "   - Current Bid: " << item.getCurrentBid() << " CP\n";
    }
}

void GuestView::searchByCategory(std::vector<Item> &items)
{
    std::vector<std::string> categories = {"Electronics", "Collectibles", "Furniture", "Vehicles"};
    std::cout << "Available Categories:\n";
    for (size_t i = 0; i < categories.size(); ++i)
    {
        std::cout << i + 1 << ". " << categories[i] << "\n";
    }

    int categoryChoice;
    std::cout << "Enter your choice: ";
    std::cin >> categoryChoice;

    if (categoryChoice > 0 && categoryChoice <= categories.size())
    {
        std::string category = categories[categoryChoice - 1];
        std::vector<Item> results;
        for (const auto &item : items)
        {
            if (item.getCategory() == category)
            {
                results.push_back(item);
            }
        }

        if (results.empty())
        {
            std::cout << "No items found in category \"" << category << "\".\n";
            return;
        }

        std::cout << "Search Results in \"" << category << "\":\n";
        for (size_t i = 0; i < results.size(); ++i)
        {
            const auto &item = results[i];
            std::cout << i + 1 << ". " << item.getName() << "\n"
                      << "   - Category: " << item.getCategory() << "\n"
                      << "   - Description: " << item.getShortDescription() << "\n"
                      << "   - Current Bid: " << item.getCurrentBid() << " CP\n";
        }
    }
}

void GuestView::searchByCPRange(std::vector<Item> &items)
{
    double minCP, maxCP;
    std::cout << "Enter the minimum CP: ";
    std::cin >> minCP;
    std::cout << "Enter the maximum CP: ";
    std::cin >> maxCP;

    std::vector<Item> results;
    for (const auto &item : items)
    {
        if (item.getCurrentBid() >= minCP && item.getCurrentBid() <= maxCP)
        {
            results.push_back(item);
        }
    }

    if (results.empty())
    {
        std::cout << "No items found in the CP range " << minCP << " - " << maxCP << ".\n";
        return;
    }

    std::cout << "Search Results in CP range " << minCP << " - " << maxCP << ":\n";
    for (size_t i = 0; i < results.size(); ++i)
    {
        const auto &item = results[i];
        std::cout << i + 1 << ". " << item.getName() << "\n"
                  << "   - Category: " << item.getCategory() << "\n"
                  << "   - Description: " << item.getShortDescription() << "\n"
                  << "   - Current Bid: " << item.getCurrentBid() << " CP\n";
    }
}

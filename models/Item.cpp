#include "Item.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

// Helper function to get the current date in YYYY/MM/DD format
string getCurrentDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    ostringstream oss;
    oss << 1900 + ltm->tm_year << "/"
        << setw(2) << setfill('0') << 1 + ltm->tm_mon << "/"
        << setw(2) << setfill('0') << ltm->tm_mday;
    return oss.str();
}

// Helper function to validate user input for end date
bool validateDateFormat(const string &date)
{
    if (date.size() != 10 || date[4] != '/' || date[7] != '/')
    {
        cout << "Invalid date format. Please enter the date as YYYY/MM/DD." << endl;
        return false;
    }
    return true;
}

// Constructor
Item::Item(int id, const string &name, const string &category, const string &description, int startBid, int increment, const string &endDate, float minRating, int sellerId)
{
    itemID = id;
    itemName = name;
    this->category = category;
    this->description = description;
    starting_bid = startBid;
    bid_increment = increment;
    creation_datetime = getCurrentDate();
    if (validateDateFormat(endDate))
    {
        end_datetime = endDate;
    }
    else
    {
        end_datetime = "Invalid date";
    }
    minium_rating = minRating;
    sellerID = sellerId;
    highestBidder = "None";
}

// Getters
int Item::getItemID() const { return itemID; }
string Item::getItemName() const { return itemName; }
string Item::getCategory() const { return category; }
string Item::getDescription() const { return description; }
int Item::getStartingBid() const { return starting_bid; }
int Item::getBidIncrement() const { return bid_increment; }
string Item::getCreationDateTime() const { return creation_datetime; }
string Item::getEndDateTime() const { return end_datetime; }
float Item::getMinimumRating() const { return minium_rating; }
int Item::getSellerID() const { return sellerID; }
string Item::getHighestBidder() const { return highestBidder; }

// Setters
void Item::setItemName(const string &name) {
    if (bid.empty()) {
        itemName = name;
    } else {
        cout << "Cannot modify the item name after a bid has been placed." << endl;
    }
}
void Item::setCategory(const string &category) {
    if (bid.empty()) {
        this->category = category;
    } else {
        cout << "Cannot modify the category after a bid has been placed." << endl;
    }
}
void Item::setDescription(const string &description) {
    if (bid.empty()) {
        this->description = description;
    } else {
        cout << "Cannot modify the description after a bid has been placed." << endl;
    }
}
void Item::setStartingBid(int bid) {
    if (this->bid.empty()) {
        starting_bid = bid;
    } else {
        cout << "Cannot modify the starting bid after a bid has been placed." << endl;
    }
}
void Item::setBidIncrement(int increment) {
    if (bid.empty()) {
        bid_increment = increment;
    } else {
        cout << "Cannot modify the bid increment after a bid has been placed." << endl;
    }
}
void Item::setEndDateTime(const string &endDate) {
    if (bid.empty() && validateDateFormat(endDate)) {
        end_datetime = endDate;
    } else {
        cout << "Cannot modify the end date after a bid has been placed or invalid format." << endl;
    }
}
void Item::setHighestBidder(const string &bidder) { highestBidder = bidder; }

// Display item details
void Item::displayItemDetails() const
{
    cout << "Item ID: " << itemID << endl;
    cout << "Item Name: " << itemName << endl;
    cout << "Category: " << category << endl;
    cout << "Description: " << description << endl;
    cout << "Starting Bid: " << starting_bid << " CP" << endl;
    cout << "Bid Increment: " << bid_increment << " CP" << endl;
    cout << "Creation Date: " << creation_datetime << endl;
    cout << "End Date: " << end_datetime << endl;
    cout << "Minimum Rating: " << minium_rating << endl;
    cout << "Seller ID: " << sellerID << endl;
    cout << "Highest Bidder: " << highestBidder << endl;
}

// Add a bid
void Item::addBid(const Bid &newBid)
{
    bid.push_back(newBid);
    if (newBid.getBidAmount() > getHighestBid())
    {
        highestBidder = newBid.getBidderName();
    }
}

// Remove item listing
bool Item::removeItemListing()
{
    if (bid.empty()) {
        cout << "Item listing removed successfully." << endl;
        return true;
    } else {
        cout << "Cannot remove the listing after a bid has been placed." << endl;
        return false;
    }
}

// Get highest bid
int Item::getHighestBid() const
{
    int highest = starting_bid;
    for (const auto &b : bid)
    {
        if (b.getBidAmount() > highest)
        {
            highest = b.getBidAmount();
        }
    }
    return highest;
}

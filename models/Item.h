#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include "Bid.h"
using namespace std;

class Item {
private:
    int itemID;
    string itemName;
    string category;
    string description;
    int starting_bid;
    int bid_increment;
    string creation_datetime;
    string end_datetime;
    float minium_rating;
    int sellerID;
    string highestBidder;
    vector<Bid> bid;

public:
    // Constructor
    Item(int id, const string &name, const string &category, const string &description, int startBid, int increment, const string &endDate, float minRating, int sellerId);

    // Getters
    int getItemID() const;
    string getItemName() const;
    string getCategory() const;
    string getDescription() const;
    int getStartingBid() const;
    int getBidIncrement() const;
    string getCreationDateTime() const;
    string getEndDateTime() const;
    float getMinimumRating() const;
    int getSellerID() const;
    string getHighestBidder() const;

    // Setters
    void setItemName(const string &name);
    void setCategory(const string &category);
    void setDescription(const string &description);
    void setStartingBid(int bid);
    void setBidIncrement(int increment);
    void setEndDateTime(const string &endDate);
    void setHighestBidder(const string &bidder);

    // Methods
    void displayItemDetails() const;
    void addBid(const Bid &newBid);
    bool removeItemListing();
    int getHighestBid() const;
};

#endif // ITEM_H

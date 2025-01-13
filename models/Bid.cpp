#include "Bid.h"
#include <iostream>
using namespace std;

// Constructor
Bid::Bid(int itemID, const int &bidderID, int bidAmount)
{
    this->itemID = itemID;
    this->bidderID = bidderID;
    this->bidAmount = bidAmount;
}

// Getters
int Bid::getItemID() const
{
    return itemID;
}

int Bid::getBidderID() const
{
    return bidderID;
}

int Bid::getBidAmount() const
{
    return bidAmount;
}

// Display bid details
void Bid::displayBidDetails() const
{
    cout << "Item ID: " << itemID << ", Bidder: " << bidderID << ", Amount: " << bidAmount << " CP" << endl;
}

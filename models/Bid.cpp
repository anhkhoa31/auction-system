#include "Bid.h"
#include <iostream>
using namespace std;

// Constructor
Bid::Bid(int itemID, const string &bidderName, int bidAmount)
{
    this->itemID = itemID;
    this->bidderName = bidderName;
    this->bidAmount = bidAmount;
}

// Getters
int Bid::getItemID() const
{
    return itemID;
}

string Bid::getBidderName() const
{
    return bidderName;
}

int Bid::getBidAmount() const
{
    return bidAmount;
}

// Display bid details
void Bid::displayBidDetails() const
{
    cout << "Item ID: " << itemID << ", Bidder: " << bidderName << ", Amount: " << bidAmount << " CP" << endl;
}

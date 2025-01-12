#ifndef BID_H
#define BID_H

#include <string>
using namespace std;

class Bid
{
private:
    int itemID;
    string bidderName;
    int bidAmount;

public:
    // Constructor
    Bid(int itemID, const string &bidderName, int bidAmount);

    // Getters
    int getItemID() const;
    string getBidderName() const;
    int getBidAmount() const;

    // Methods
    void displayBidDetails() const;
};

#endif // BID_H

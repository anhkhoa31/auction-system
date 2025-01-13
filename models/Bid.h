#ifndef BID_H
#define BID_H

#include <string>
using namespace std;

class Bid
{
private:
    int itemID;
    int bidderID;
    int bidAmount;

public:
    // Constructor
    Bid(int itemID, const int &bidderID, int bidAmount);

    // Getters
    int getItemID() const;
    int getBidderID() const;
    int getBidAmount() const;

    // Methods
    void displayBidDetails() const;
};

#endif // BID_H

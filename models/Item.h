#ifndef ITEM_H
#define ITEM_H
#include "Bid.h"
#include <string>
#include <vector>
class Item {
private:
    int id;
    std::string name;
    std::string category;
    std::string shortDescription;
    double startingBid;
    double currentBid;
    double bidIncrement;
    std::string endDate;
    int minBuyerRating;
    double sellerRating;
    int sellerId;
    int highestBidderId;
    // vector<Bid> bid;
public:
    Item();

    Item(int id,
         const std::string& name,
         const std::string& category,
         const std::string& shortDescription,
         double startingBid,
         double bidIncrement,
         const std::string& endDate,
         int minBuyerRating,
         double sellerRating,
         int sellerId);

    int getId() const;
    std::string getName() const;
    std::string getCategory() const;
    std::string getShortDescription() const;
    double getStartingBid() const;
    double getCurrentBid() const;
    double getBidIncrement() const;
    std::string getEndDate() const;
    int getMinBuyerRating() const;
    double getSellerRating() const;
    int getSellerId() const;
    int getHighestBidderId() const;

    void setId(int id);
    void setName(const std::string& name);
    void setCategory(const std::string& category);
    void setShortDescription(const std::string& shortDescription);
    void setStartingBid(double startingBid);
    void setCurrentBid(double currentBid);
    void setBidIncrement(double bidIncrement);
    void setEndDate(const std::string& endDate);
    void setMinBuyerRating(int minBuyerRating);
    void setSellerRating(double sellerRating);
    void setSellerId(int sellerId);
    void setHighestBidderId(int highestBidderId);

    bool isEligibleToBid(int buyerRating) const;
    void addBid(const Bid &newBid);
    int getHighestBid() const;
    

};

#endif // ITEM_H

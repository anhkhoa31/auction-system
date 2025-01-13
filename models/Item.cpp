#include "Item.h"

Item::Item()
    : id(0),
      name(""),
      category(""),
      shortDescription(""),
      startingBid(0.0),
      currentBid(0.0),
      bidIncrement(0.0),
      endDate(""),
      minBuyerRating(0),
      sellerRating(0.0),
      sellerId(0),
      highestBidderId(-1) // default highest bidder
{
}

Item::Item(int id,
           const std::string& name,
           const std::string& category,
           const std::string& shortDescription,
           double startingBid,
           double bidIncrement,
           const std::string& endDate,
           int minBuyerRating,
           double sellerRating,
           int sellerId)
    : id(id),
      name(name),
      category(category),
      shortDescription(shortDescription),
      startingBid(startingBid),
      currentBid(startingBid),
      bidIncrement(bidIncrement),
      endDate(endDate),
      minBuyerRating(minBuyerRating),
      sellerRating(sellerRating),
      sellerId(sellerId),
      highestBidderId(-1) // default highest bidder
{
}

// Getters and setters
int Item::getId() const {
    return id;
}
void Item::setId(int id) {
    this->id = id;
}

std::string Item::getName() const {
    return name;
}
void Item::setName(const std::string& name) {
    this->name = name;
}

std::string Item::getCategory() const {
    return category;
}
void Item::setCategory(const std::string& category) {
    this->category = category;
}

std::string Item::getShortDescription() const {
    return shortDescription;
}
void Item::setShortDescription(const std::string& shortDescription) {
    this->shortDescription = shortDescription;
}

double Item::getStartingBid() const {
    return startingBid;
}
void Item::setStartingBid(double startingBid) {
    this->startingBid = startingBid;
}

double Item::getCurrentBid() const {
    return currentBid;
}
void Item::setCurrentBid(double currentBid) {
    this->currentBid = currentBid;
}

double Item::getBidIncrement() const {
    return bidIncrement;
}
void Item::setBidIncrement(double bidIncrement) {
    this->bidIncrement = bidIncrement;
}

std::string Item::getEndDate() const {
    return endDate;
}
void Item::setEndDate(const std::string& endDate) {
    this->endDate = endDate;
}

int Item::getMinBuyerRating() const {
    return minBuyerRating;
}
void Item::setMinBuyerRating(int minBuyerRating) {
    this->minBuyerRating = minBuyerRating;
}

double Item::getSellerRating() const {
    return sellerRating;
}
void Item::setSellerRating(double sellerRating) {
    this->sellerRating = sellerRating;
}

int Item::getSellerId() const {
    return sellerId;
}
void Item::setSellerId(int sellerId) {
    this->sellerId = sellerId;
}

int Item::getHighestBidderId() const {
    return highestBidderId;
}
void Item::setHighestBidderId(int highestBidderId) {
    this->highestBidderId = highestBidderId;
}

// Utility Methods
bool Item::isEligibleToBid(int buyerRating) const {
    return buyerRating >= minBuyerRating;
}



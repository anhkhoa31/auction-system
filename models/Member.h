#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "Item.h"  // Include Item so we can use std::vector<Item>

class Member {
private:
    int memberID;
    std::string username;
    std::string password;
    std::string name;
    std::string phoneNumber;
    std::string email;
    std::string IDType;
    std::string IDNumber;
    int creditPoints;
    int avgRatings;

    // NEW FIELDS
    std::vector<Item> bidItems;   // Items the member is currently bidding on
    std::vector<Item> sellItems;  // Items the member has posted for sale

public:
    Member();
    Member(int id,
           const std::string& username,
           const std::string& password,
           const std::string& name,
           const std::string& phoneNumber,
           const std::string& email,
           const std::string& IDType,
           const std::string& IDNumber);

    // Existing getters and setters
    int getMemberID() const;
    void setMemberID(int id);

    std::string getUsername() const;
    void setUsername(const std::string& user);

    std::string getPassword() const;
    void setPassword(const std::string& pass);

    std::string getName() const;
    void setName(const std::string& name);

    std::string getPhoneNumber() const;
    void setPhoneNumber(const std::string& phone);

    std::string getEmail() const;
    void setEmail(const std::string& email);

    std::string getIDType() const;
    void setIDType(const std::string& idType);

    std::string getIDNumber() const;
    void setIDNumber(const std::string& idNumber);

    int getCreditPoints() const;
    void setCreditPoints(int points);

    int getAvgRatings() const;
    void setAvgRatings(int rating);

    // NEW METHODS for bidItems and sellItems
    std::vector<Item>& getBidItems();
    void addBidItem(const Item& item);

    std::vector<Item>& getSellItems();
    void addSellItem(const Item& item);
    
    void deductCreditPoints(double amount);
    void addCreditPoints(double amount);
};

#endif

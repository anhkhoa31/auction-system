#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>

// Forward declare Item if necessary
// class Item;

class Member {
private:
    int memberID;
    std::string username;
    std::string password;       // must not be "12345" or "password"
    std::string name;
    std::string phoneNumber;
    std::string email;
    std::string IDType;
    std::string IDNumber;
    int creditPoints;           // (new member set to 0)
    int avgRatings;             // (default rating = 3)
    std::vector<int> ratingThroughTransaction;
    // std::vector<Item> bidItems;
    // std::vector<Item> sellItems;

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

    // Getters and setters
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

    std::vector<int> getRatingThroughTransaction() const;
    void addRating(int rating);

    // For future item management if needed:
    // void addBidItem(const Item& item);
    // void addSellItem(const Item& item);
    // etc.
};

#endif

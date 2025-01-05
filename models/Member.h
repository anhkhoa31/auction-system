#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>

struct Member {
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
    std::vector<int> ratingThroughTransaction;
    std::vector<std::string> bidItems;
    std::vector<std::string> sellItems;
};

#endif

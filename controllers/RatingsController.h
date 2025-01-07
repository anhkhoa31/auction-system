#ifndef RATINGS_CONTROLLER_H
#define RATINGS_CONTROLLER_H

#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

struct User {
    double buyerRating = 3.0;
    double sellerRating = 3.0;
    int buyerRatingsCount = 0;
    int sellerRatingsCount = 0;
};

extern map<string, User> users;

void rateUser(User &user, double rating, bool isSeller);

void rateTransaction(const string &buyerUsername, const string &sellerUsername, double buyerRating, double sellerRating);

double getSellerRating(const string &username);

double getBuyerRating(const string &username);

#endif

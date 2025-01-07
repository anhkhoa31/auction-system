#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

struct User {
    double buyerRating = 3.0;  // Default buyer rating
    double sellerRating = 3.0; // Default seller rating
    int buyerRatingsCount = 0;
    int sellerRatingsCount = 0;
};

map<string, User> users; // Users database (will be changed after)

void rateUser(User &user, double rating, bool isSeller) {
    if (isSeller) {
        user.sellerRating = ((user.sellerRating * user.sellerRatingsCount) + rating) / (user.sellerRatingsCount + 1);
        user.sellerRatingsCount++;
    } else {
        user.buyerRating = ((user.buyerRating * user.buyerRatingsCount) + rating) / (user.buyerRatingsCount + 1);
        user.buyerRatingsCount++;
    }
}

// Function to handle rating a transaction
void rateTransaction(const string &buyerUsername, const string &sellerUsername, double buyerRating, double sellerRating) {
    // Check if buyer and seller exist in the database
    if (users.find(buyerUsername) == users.end() || users.find(sellerUsername) == users.end()) {
        cout << "Error: Buyer or seller username not found.\n";
        return;
    }

    // Validate ratings
    if (buyerRating < 1 || buyerRating > 5 || sellerRating < 1 || sellerRating > 5) {
        cout << "Error: Ratings must be between 1 and 5.\n";
        return;
    }

    // Update ratings
    User &buyer = users[buyerUsername];
    User &seller = users[sellerUsername];

    rateUser(buyer, buyerRating, false); // Rate the buyer
    rateUser(seller, sellerRating, true); // Rate the seller

    cout << "Transaction rated successfully.\n";
}

// Retrieve a user's seller rating
double getSellerRating(const string &username) {
    if (users.find(username) != users.end()) {
        return users[username].sellerRating;
    }
    cout << "Error: Username not found.\n";
    return -1; // Invalid rating value
}

// Retrieve a user's buyer rating
double getBuyerRating(const string &username) {
    if (users.find(username) != users.end()) {
        return users[username].buyerRating;
    }
    cout << "Error: Username not found.\n";
    return -1; // Invalid rating value
}


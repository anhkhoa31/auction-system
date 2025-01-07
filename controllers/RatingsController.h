#ifndef RATINGSCONTROLLER_H
#define RATINGSCONTROLLER_H

#include <string>
#include <vector>
#include <map>

class RatingsAndReviews {
    struct Review {
        int rating;
        std::string reviewText;
    };
    std::map<std::string, std::vector<Review>> userRatings;
    std::map<std::string, double> averageRatings;
    void updateAverageRating(const std::string& userID);
    void addReview();
    double getAverageRating(const std::string& userID);
    std::vector<std::string> getReviews(const std::string& userID);
    void displayReviews(const std::string& userID);
};
void interactiveMenu();

#endif

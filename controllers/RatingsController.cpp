#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <stdexcept>

class RatingsAndReviews {
private:
    struct Review {
        int rating;
        std::string reviewText;
    };

    // Stores user reviews
    std::map<std::string, std::vector<Review>> userRatings;

    // Stores average ratings for users
    std::map<std::string, double> averageRatings;

    // Update average rating after a new review
    void updateAverageRating(const std::string& userID) {
        const auto& reviews = userRatings[userID];
        if (reviews.empty()) {
            averageRatings[userID] = 3.0; // Default rating
            return;
        }

        double sum = 0.0;
        for (const auto& review : reviews) {
            sum += review.rating;
        }
        averageRatings[userID] = sum / reviews.size();
    }

public:
    RatingsAndReviews() = default;

    // Add a review for a user
    void addReview(const std::string& fromUserID, const std::string& toUserID, int rating, const std::string& reviewText = "") {
        // Validate rating
        if (rating < 1 || rating > 5) {
            throw std::invalid_argument("Invalid choice, must be between 1 and 5");
        }

        // Add the review
        userRatings[toUserID].push_back({rating, reviewText});
        updateAverageRating(toUserID);
    }

    // Get the average rating of a user
    double getAverageRating(const std::string& userID) const {
        auto it = averageRatings.find(userID);
        if (it != averageRatings.end()) {
            return it->second;
        }
        return 3.0; // Default rating for new users
    }

    // Get all reviews for a user
    std::vector<std::string> getReviews(const std::string& userID) const {
        std::vector<std::string> reviews;
        auto it = userRatings.find(userID);
        if (it != userRatings.end()) {
            for (const auto& review : it->second) {
                std::ostringstream oss;
                oss << "Rating: " << review.rating << " | Comment: " << review.reviewText;
                reviews.push_back(oss.str());
            }
        }
        return reviews;
    }

    // Display reviews and average rating for a user
    void displayReviews(const std::string& userID) const {
        std::cout << "Reviews for User: " << userID << "\n";
        std::cout << "Average Rating: " << std::fixed << std::setprecision(1) << getAverageRating(userID) << "\n";
        const auto& reviews = getReviews(userID);
        for (const auto& review : reviews) {
            std::cout << review << "\n";
        }
        if (reviews.empty()) {
            std::cout << "No reviews yet\n";
        }
    }
};

void interactiveMenu() {
    RatingsAndReviews ratingsSystem;
    std::string fromUserID, toUserID, reviewText, userID;
    int choice, rating;

    while (true) {
        std::cout << "\n--- Ratings and Reviews Feature ---\n";
        std::cout << "1. Add a Review\n";
        std::cout << "2. View User's Average Rating\n";
        std::cout << "3. View All Reviews for a User\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            // Add review
            std::cout << "Enter your User ID: "; // Stimulating 2 people for testing purpose, changed later
            std::cin >> fromUserID;
            std::cout << "Enter the User ID to review: "; // Stimulating 2 people for testing purpose, changed later
            std::cin >> toUserID;
            std::cout << "Enter rating (1-5): ";
            std::cin >> rating;
            std::cin.ignore();
            std::cout << "Enter review: ";
            std::getline(std::cin, reviewText);

            try {
                ratingsSystem.addReview(fromUserID, toUserID, rating, reviewText);
                std::cout << "Review added successfully\n";
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
            }
            break;

        case 2:
            // View average rating
            std::cout << "Enter a User ID to view: ";
            std::cin >> userID;
            std::cout << "Average Rating for " << userID << ": "
                      << std::fixed << std::setprecision(1) << ratingsSystem.getAverageRating(userID) << "\n";
            break;

        case 3:
            // View all reviews
            std::cout << "Enter the User ID to view: ";
            std::cin >> userID;
            ratingsSystem.displayReviews(userID);
            break;

        case 4:
            // Exit
            std::cout << "Exiting\n";
            return;

        default:
            std::cout << "Invalid choice. Try again\n";
        }
    }
}

int main() {
    interactiveMenu();
    return 0;
}

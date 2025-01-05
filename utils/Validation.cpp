#include "../utils/Validation.h"
#include <regex>

bool isStrongPassword(const std::string& password) {
    // Password must contain at least:
    // - One letter (uppercase or lowercase)
    // - One digit
    // - One special character
    // - At least 8 characters long
    std::regex strongPasswordRegex("^(?=.*[A-Za-z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
    return std::regex_match(password, strongPasswordRegex);
}

bool isValidEmail(const std::string& email) {
    // Basic email validation using regex
    std::regex emailRegex(R"(^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    return std::regex_match(email, emailRegex);
}

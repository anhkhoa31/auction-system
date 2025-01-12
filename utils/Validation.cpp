#include "Validation.h"

bool Validation::isValidPassword(const std::string& password) {
    // Reject obviously weak passwords
    if (password == "12345" || password == "password") {
        return false;
    }
    // You can add more rules (minimum length, special chars, etc.)
    if (password.size() < 5) {
        return false;
    }
    return true;
}

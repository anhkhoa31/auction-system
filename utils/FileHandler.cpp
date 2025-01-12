#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Methods for handling Member data
std::vector<Member> FileHandler::readMembersFromCSV(const std::string& filePath) {
    std::vector<Member> members;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filePath << std::endl;
        return members;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 10) {
            std::cerr << "Skipping line due to insufficient columns: " << line << std::endl;
            continue;
        }

        Member m;
        try {
            m.setMemberID(std::stoi(tokens[0]));
        } catch (...) {
            continue;
        }

        m.setUsername(tokens[1]);
        m.setPassword(tokens[2]);
        m.setName(tokens[3]);
        m.setPhoneNumber(tokens[4]);
        m.setEmail(tokens[5]);
        m.setIDType(tokens[6]);
        m.setIDNumber(tokens[7]);

        try {
            m.setCreditPoints(std::stoi(tokens[8]));
        } catch (...) {
            m.setCreditPoints(0);
        }

        try {
            m.setAvgRatings(std::stoi(tokens[9]));
        } catch (...) {
            m.setAvgRatings(3);
        }

        members.push_back(m);
    }

    file.close();
    return members;
}

void FileHandler::writeMembersToCSV(const std::string& filePath, const std::vector<Member>& members) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filePath << std::endl;
        return;
    }

    for (const auto& m : members) {
        file << m.getMemberID() << ","
             << m.getUsername() << ","
             << m.getPassword() << ","
             << m.getName() << ","
             << m.getPhoneNumber() << ","
             << m.getEmail() << ","
             << m.getIDType() << ","
             << m.getIDNumber() << ","
             << m.getCreditPoints() << ","
             << m.getAvgRatings() << "\n";
    }

    file.close();
}

// Methods for handling Item data
std::vector<Item> FileHandler::readItemsFromCSV(const std::string& filePath) {
    std::vector<Item> items;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filePath << std::endl;
        return items;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 10) continue;

        items.emplace_back(
            std::stoi(tokens[0]),          // ID
            tokens[1],                     // Name
            tokens[2],                     // Category
            tokens[3],                     // Short Description
            std::stod(tokens[4]),          // Starting Bid
            std::stod(tokens[5]),          // Bid Increment
            tokens[6],                     // End Date
            std::stoi(tokens[7]),          // Minimum Buyer Rating
            std::stod(tokens[8]),          // Seller Rating
            std::stoi(tokens[9])           // Seller ID
        );
    }

    file.close();
    return items;
}

void FileHandler::writeItemsToCSV(const std::string& filePath, const std::vector<Item>& items) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filePath << std::endl;
        return;
    }

    for (const auto& item : items) {
        file << item.getId() << ","
             << item.getName() << ","
             << item.getCategory() << ","
             << item.getShortDescription() << ","
             << item.getStartingBid() << ","
             << item.getBidIncrement() << ","
             << item.getEndDate() << ","
             << item.getMinBuyerRating() << ","
             << item.getSellerRating() << ","
             << item.getSellerId() << "\n";
    }

    file.close();
}

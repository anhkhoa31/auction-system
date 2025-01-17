#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include "../models/Item.h"
#include <iostream>

/**
 * readMembersFromCSV:
 *   - Reads each line from a CSV file
 *   - Splits by comma
 *   - Builds a Member object
 *   - Returns a vector<Member>
 */
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

        // Split line by comma
        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        /**
         * We’ll define the CSV columns in this exact order (10 columns):
         *   0: memberID
         *   1: username
         *   2: password
         *   3: name
         *   4: phoneNumber
         *   5: email
         *   6: IDType
         *   7: IDNumber
         *   8: creditPoints
         *   9: avgRatings
         *
         * If we don't have at least 10 columns, skip this line.
         */
        if (tokens.size() < 10) {
            std::cerr << "Skipping line due to insufficient columns: " << line << std::endl;
            continue;
        }

        Member m;
        
        // 0: memberID
        try {
            m.setMemberID(std::stoi(tokens[0]));
        } catch (...) {
            // handle parse error if needed
            continue;
        }

        // 1: username
        m.setUsername(tokens[1]);
        // 2: password
        m.setPassword(tokens[2]);
        // 3: name
        m.setName(tokens[3]);
        // 4: phoneNumber
        m.setPhoneNumber(tokens[4]);
        // 5: email
        m.setEmail(tokens[5]);
        // 6: IDType
        m.setIDType(tokens[6]);
        // 7: IDNumber
        m.setIDNumber(tokens[7]);

        // 8: creditPoints
        try {
            m.setCreditPoints(std::stoi(tokens[8]));
        } catch (...) {
            m.setCreditPoints(0);
        }

        // 9: avgRatings
        try {
            m.setAvgRatings(std::stoi(tokens[9]));
        } catch (...) {
            m.setAvgRatings(3);
        }

        // Add this Member to the list
        members.push_back(m);
    }

    file.close();
    return members;
}

/**
 * writeMembersToCSV:
 *   - Loops through the vector of Members
 *   - Writes each Member to a single line in the CSV
 */
void FileHandler::writeMembersToCSV(const std::string& filePath, const std::vector<Member>& members) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Cannot open file: " << filePath << std::endl;
        return;
    }

    for (const auto& m : members) {
        // Maintain the same column order as in readMembersFromCSV!
        file << m.getMemberID() << ","   // 0
             << m.getUsername() << ","   // 1
             << m.getPassword() << ","   // 2
             << m.getName() << ","       // 3
             << m.getPhoneNumber() << ","// 4
             << m.getEmail() << ","      // 5
             << m.getIDType() << ","     // 6
             << m.getIDNumber() << ","   // 7
             << m.getCreditPoints() << "," // 8
             << m.getAvgRatings()         // 9
             << std::endl;
    }

    file.close();
}

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

        items.emplace_back(
            std::stoi(tokens[0]),          // ID
            tokens[1],                     // Name
            tokens[2],                     // Category
            tokens[3],                     // Short Description
            std::stod(tokens[4]),          // Starting Bid
            std::stod(tokens[5]),          // Current Bid
            std::stod(tokens[6]),          // Bid Increment
            tokens[7],                     // End Date
            std::stoi(tokens[8]),          // Minimum Buyer Rating
            std::stod(tokens[9]),          // Seller Rating
            std::stoi(tokens[10]),         // Member ID
            std::stoi(tokens[11])          // Highest Bidder ID
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
             << item.getMemberId() << "\n";
    }

    file.close();
}


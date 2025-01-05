#include "../utils/FileHandler.h"
#include "models/Member.h"
#include <fstream>
#include <vector>
#include <sstream>

std::vector<Member> loadMembersFromCSV() {
    std::vector<Member> members;
    std::ifstream file("data/members.csv");
    std::string line;

    // if (!file.is_open()) {
    //     std::cerr << "Error: Could not open members.csv file." << std::endl;
    //     return members;
    // }

    // Skip header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        Member member;
        std::string token;

        // Parse CSV fields
        std::getline(ss, token, ',');
        member.memberID = std::stoi(token);

        std::getline(ss, member.username, ',');

        std::getline(ss, member.password, ',');

        std::getline(ss, member.name, ',');

        std::getline(ss, member.phoneNumber, ',');

        std::getline(ss, member.email, ',');

        std::getline(ss, member.IDType, ',');

        std::getline(ss, member.IDNumber, ',');

        std::getline(ss, token, ',');
        member.creditPoints = std::stoi(token);

        std::getline(ss, token, ',');
        member.avgRatings = std::stoi(token);

        members.push_back(member);
    }

    file.close();
    return members;
}

void saveMembersToCSV(const std::vector<Member>& members) {
    std::ofstream file("data/members.csv");

    // if (!file.is_open()) {
    //     std::cerr << "Error: Could not open members.csv file for writing." << std::endl;
    //     return;
    // }

    // Write header
    file << "memberID,username,password,name,phoneNumber,email,IDType,IDNumber,creditPoints,avgRatings\n";

    for (const auto& member : members) {
        file << member.memberID << "," << member.username << "," << member.password << ","
             << member.name << "," << member.phoneNumber << "," << member.email << ","
             << member.IDType << "," << member.IDNumber << "," << member.creditPoints << ","
             << member.avgRatings << "\n";
    }

    file.close();
}

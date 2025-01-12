#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
#include "../models/Member.h"
#include "../models/Item.h"

class FileHandler {
public:
    // Methods for handling Member data
    static std::vector<Member> readMembersFromCSV(const std::string& filePath);
    static void writeMembersToCSV(const std::string& filePath, const std::vector<Member>& members);

    // Methods for handling Item data
    static std::vector<Item> readItemsFromCSV(const std::string& filePath);
    static void writeItemsToCSV(const std::string& filePath, const std::vector<Item>& items);
};

#endif // FILEHANDLER_H

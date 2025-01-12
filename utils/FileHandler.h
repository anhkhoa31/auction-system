#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
#include "../models/Member.h"

class FileHandler {
public:
    static std::vector<Member> readMembersFromCSV(const std::string& filePath);
    static void writeMembersToCSV(const std::string& filePath, const std::vector<Member>& members);
};

#endif

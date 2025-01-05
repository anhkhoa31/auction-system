#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "models/Member.h"
#include <vector>

std::vector<Member> loadMembersFromCSV();
void saveMembersToCSV(const std::vector<Member>& members);

#endif

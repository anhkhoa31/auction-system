#ifndef AUTHVIEW_H
#define AUTHVIEW_H

#include <vector>
#include "../models/Member.h"

class AuthView {
public:
    static void showLoginScreen(std::vector<Member>& members);
    static void showRegisterScreen(std::vector<Member>& members);
};

#endif

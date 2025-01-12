#include "Member.h"

Member::Member()
    : memberID(0),
      username(""),
      password(""),
      name(""),
      phoneNumber(""),
      email(""),
      IDType(""),
      IDNumber(""),
      creditPoints(0),
      avgRatings(3) // default rating
{
}

Member::Member(int id,
               const std::string& user,
               const std::string& pass,
               const std::string& nm,
               const std::string& phone,
               const std::string& mail,
               const std::string& type,
               const std::string& number)
    : memberID(id),
      username(user),
      password(pass),
      name(nm),
      phoneNumber(phone),
      email(mail),
      IDType(type),
      IDNumber(number),
      creditPoints(0),
      avgRatings(3) // default rating
{
}

// Getters and setters
int Member::getMemberID() const {
    return memberID;
}
void Member::setMemberID(int id) {
    memberID = id;
}

std::string Member::getUsername() const {
    return username;
}
void Member::setUsername(const std::string& user) {
    username = user;
}

std::string Member::getPassword() const {
    return password;
}
void Member::setPassword(const std::string& pass) {
    password = pass;
}

std::string Member::getName() const {
    return name;
}
void Member::setName(const std::string& nm) {
    name = nm;
}

std::string Member::getPhoneNumber() const {
    return phoneNumber;
}
void Member::setPhoneNumber(const std::string& phone) {
    phoneNumber = phone;
}

std::string Member::getEmail() const {
    return email;
}
void Member::setEmail(const std::string& mail) {
    email = mail;
}

std::string Member::getIDType() const {
    return IDType;
}
void Member::setIDType(const std::string& type) {
    IDType = type;
}

std::string Member::getIDNumber() const {
    return IDNumber;
}
void Member::setIDNumber(const std::string& number) {
    IDNumber = number;
}

int Member::getCreditPoints() const {
    return creditPoints;
}
void Member::setCreditPoints(int points) {
    creditPoints = points;
}

int Member::getAvgRatings() const {
    return avgRatings;
}
void Member::setAvgRatings(int rating) {
    avgRatings = rating;
}

std::vector<int> Member::getRatingThroughTransaction() const {
    return ratingThroughTransaction;
}
void Member::addRating(int rating) {
    ratingThroughTransaction.push_back(rating);
}

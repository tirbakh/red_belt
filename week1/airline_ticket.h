#pragma once

#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Date {
  int year, month, day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.year, lhs.month, lhs.day} < vector<int>{rhs.year, rhs.month, rhs.day};
}

bool operator==(const Date& lhs, const Date& rhs) {
    return !(lhs < rhs || rhs < lhs);
}

ostream& operator<<(ostream& os, const Date& d) {
    os << d.year << "-" << d.month << "-" << d.day;
    return os;
}

struct Time {
  int hours, minutes;
};

ostream& operator<<(ostream& os, const Time& d) {
    os << d.hours << ":" << d.minutes;
    return os;
}

bool operator<(const Time& lhs, const Time& rhs) {
    return vector<int>{lhs.hours, lhs.minutes} < vector<int>{rhs.hours, rhs.minutes};
}

bool operator==(const Time& lhs, const Time& rhs) {
    return !(lhs < rhs || rhs < lhs);
}

struct AirlineTicket {
  string from;
  string to;
  string airline;
  Date departure_date;
  Time departure_time;
  Date arrival_date;
  Time arrival_time;
  int price;
};

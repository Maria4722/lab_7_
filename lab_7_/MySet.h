#pragma once

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <limits>

using SetElement = int;

class MySet
{
private:
    std::set<SetElement> data;

public:
    MySet();
    MySet(std::initializer_list<SetElement> list);

    bool contains(const SetElement& element) const;

    MySet operator+(const MySet& other) const;
    MySet operator*(const MySet& other) const;
    MySet operator-(const MySet& other) const;

    bool operator<=(const MySet& other) const;
    bool operator>=(const MySet& other) const;

    friend std::ostream& operator<<(std::ostream& os, const MySet& s);
    friend std::istream& operator>>(std::istream& is, MySet& s);
};
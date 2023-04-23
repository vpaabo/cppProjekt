#ifndef ERROR_H
#define ERROR_H

#include <string>
#include <iostream>

using namespace std;

template<int N>
class Error {
    string message;

public:
    explicit Error(const string s) : message{s} {};

    string getMessage() const { return message; };
    
    friend ostream& operator<<(ostream& os, const Error<N>& e) {
        os << e.getMessage();
        return os;
    }
};

#endif
#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
using namespace std;

enum Type
{
    INTEGER, // TODO convert to float (also needs refactor everywhere)
    LPAREN,
    RPAREN,
    PLUS,
    MINUS, 
    TIMES,
    DIV,
    EOFRFR // EOF is c++ keyword

};

class Data
{
public:
    // only one place to refactor to float numbers
    int data;
    Data() = default;
    Data(int _data);
    friend ostream &operator<<(ostream &os, const Data &d);
};

class Token
{
private:
    Type type;
    Data data;
    int offset;
    int length;

public:
    Token() = default;
    Token(Type _type);
    Token(Type _type, Data _data);
    Token(Type _type, int _offset, int _length);
    Token(Type _type, Data _data, int _offset, int _length);
    Type getType();
    Data getData();
    int getOffset();
    int getLength();

    Token setPosition(int _offset, int _length);

    friend ostream &operator<<(ostream &os, const Token &t);
};

#endif
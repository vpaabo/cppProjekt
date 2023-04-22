#include <iostream>
#include "../include/Token.h"
using namespace std;

Data::Data(int _data) : data{_data} {}
ostream &operator<<(ostream &os, const Data &d)
{
    return os << d.data;
}

Token::Token(Type _type) : type{_type} {}
Token::Token(Type _type, Data _data) : type{_type}, data{_data} {}
Token::Token(Type _type, int _offset, int _length) : type{_type}, offset{_offset}, length{_length} {}
Token::Token(Type _type, Data _data, int _offset, int _length) : type{_type}, data{_data}, offset{_offset}, length{_length} {}

Type Token::getType() { return type; }
Data Token::getData() { return data; }
int Token::getOffset() { return offset; }
int Token::getLength() { return length; }

Token Token::setPosition(int _offset, int _length)
{
    this->offset = _offset;
    this->length = _length;
    return *this;
}
ostream &operator<<(ostream &os, const Token &t)
{
    static const char* const type_names[] = { "INTEGER", "LPAREN", "RPAREN", "PLUS", "MINUS", "TIMES", "DIV", "EOF" }; 

    os << "<" << type_names[static_cast<int>(t.type)];
    if (t.type == INTEGER)
        os << ":" << t.data;
    os << ">";
    return os;
}
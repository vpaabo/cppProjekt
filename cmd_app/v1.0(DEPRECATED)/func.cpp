#include "func.h"
#include <string>
#include <cstring>
using namespace std;

Parser::Parser(string nexpr){
    expr = nexpr.c_str();
}

string Parser::getExpr(){
    return (string)expr;
}

void Parser::setExpr(string nexpr){
    expr = nexpr.c_str();
}

char Parser::peek()
{
    return *expr;
}

char Parser::get()
{
    return *expr++;
}

int Parser::number()
{
    int result = get() - '0';
    while (peek() >= '0' && peek() <= '9')
    {
        result = 10*result + get() - '0';
    }
    return result;
}

int Parser::factor()
{
    if (peek() >= '0' && peek() <= '9')
        return number();
    else if (peek() == '(')
    {
        get(); // '('
        int result = expression();
        get(); // ')'
        return result;
    }
    else if (peek() == '-')
    {
        get();
        return -factor();
    }
    return 0; // error
}

int Parser::term()
{
    int result = factor();
    while (peek() == '*' || peek() == '/')
        if (get() == '*')
            result *= factor();
        else
            result /= factor();
    return result;
}

int Parser::expression()
{
    int result = term();
    while (peek() == '+' || peek() == '-')
        if (get() == '+')
            result += term();
        else
            result -= term();
    return result;
}
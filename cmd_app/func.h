#ifndef FUNC_H
#define FUNC_H

#include <string>
using namespace std;

class Parser
{
private:
    const char *expr;

public:
    Parser();
    Parser(string);

    string getExpr();
    void setExpr(string);

    char peek();
    char get();
    int number();
    int factor();
    int term();
    int expression();
};
#endif
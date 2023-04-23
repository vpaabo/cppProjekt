#include <map>

#include "Lexer.h"

using SyntaxError = Error<2>;
using RuntimeError = Error<3>;

map<string, double> symbolTable;

class Parser {
    Lexer* lexer_ptr;

    double addExpr();
    double mulExpr();
    double powExpr();
    double unaryExpr();
    double primary();

    void checkDomain(double x, double y);       // Checks for root of negative number
    double getArgument();                       // Get the argument for a function (e.g. log or exp)

public:
    Parser();

    double operator()(const string& s);
};
#include "Lexer.h"

using SyntaxError = Error<2>;
using RuntimeError = Error<3>;

class Parser {
    Lexer* lexer_ptr;

    double addExpr();
    double mulExpr();
    double primary();

public:
    double operator()(const string& s);
};
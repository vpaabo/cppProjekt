#include "../include/Parser.h"

double Parser::operator()(const string& s) {
    istringstream ist{s};
    lexer_ptr = new Lexer{ist};
    double result = addExpr();
    delete lexer_ptr;
    return result;
}

double Parser::addExpr() {
    double result = mulExpr();

    for (;;) {
        switch (lexer_ptr->getCurrentToken()) {
            case Token::PLUS:
                lexer_ptr->advance();
                result += mulExpr();
                break;
            case Token::MINUS:
                lexer_ptr->advance();
                result -= mulExpr();
                break;
            default:
                return result;
        }
    }
}

double Parser::mulExpr() {
    double result = primary();
    double x;

    for (;;) {
        switch (lexer_ptr->getCurrentToken()) {
            case Token::MUL:
                lexer_ptr->advance();
                result *= primary();
                break;
            case Token::DIV:
                lexer_ptr->advance();
                x = primary();
                if (x == 0) {
                    throw RuntimeError{"Can't divide by zero."};
                }
                result /= x;
                break;
            default:
                return result;
        }
    }
}

double Parser::primary() {
    string text = lexer_ptr->getTokenText();
    double arg;

    switch (lexer_ptr->getCurrentToken()) {
        case Token::NUMBER:
            lexer_ptr->advance();
            return stod(text);
        case Token::LPAREN:
            lexer_ptr->advance();
            arg = addExpr();
            if (lexer_ptr->getCurrentToken() != Token::RPAREN) {
                throw SyntaxError{"Missing ')'."};
            }
            lexer_ptr->advance();
            return arg;
        default:
            throw SyntaxError{"Invalid expression."};
    }
}
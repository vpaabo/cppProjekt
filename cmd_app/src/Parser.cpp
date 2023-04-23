#include <cmath>

#include "../include/Parser.h"

map<string, double> symbolTable;

Parser::Parser() {
    symbolTable["pi"] = 4.0 * atan(1.0);
    symbolTable["e"] = exp(1.0);
}

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
    double result = powExpr();
    double x;

    for (;;) {
        switch (lexer_ptr->getCurrentToken()) {
            case Token::MUL:
                lexer_ptr->advance();
                result *= powExpr();
                break;
            case Token::DIV:
                lexer_ptr->advance();
                x = powExpr();
                if (x == 0) {
                    throw RuntimeError{"can't divide by zero."};
                }
                result /= x;
                break;
            case Token::MOD:
                lexer_ptr->advance();
                x = powExpr();
                if (x == 0) {
                    throw RuntimeError{"attempting to divide by zero."};
                }
                result = fmod(result, x);
                break;
            default:
                return result;
        }
    }
}

double Parser::powExpr() {
    double result = unaryExpr();

    if (lexer_ptr->getCurrentToken() == Token::POW) {
        lexer_ptr->advance();
        double x = unaryExpr();
        checkDomain(result, x);
        return pow(result, x);
    }

    return result;
}

double Parser::unaryExpr() {
    switch (lexer_ptr->getCurrentToken()) {
        case Token::MINUS:
            lexer_ptr->advance();
            return -primary();
        default:
            return primary();
    }
}

double Parser::primary() {
    string text = lexer_ptr->getTokenText();
    double arg;

    switch (lexer_ptr->getCurrentToken()) {
        case Token::ID:
            lexer_ptr->advance();
            return symbolTable[text];
        case Token::NUMBER:
            lexer_ptr->advance();
            return stod(text);
        case Token::LPAREN:
            lexer_ptr->advance();
            arg = addExpr();
            if (lexer_ptr->getCurrentToken() != Token::RPAREN) {
                throw SyntaxError{"missing ')'."};
            }
            lexer_ptr->advance();
            return arg;
        case Token::LN:
            arg = getArgument();
            if (arg < 1) {
                throw RuntimeError{"invalid argument to ln: " + to_string(arg)};
            }
            return log(arg);
        case Token::EXP:
            return exp(getArgument());
        case Token::LOG:
            arg = getArgument();
            if (arg < 1) {
                throw RuntimeError{"invalid argument to log: " + to_string(arg)};
            }
            return log10(arg);
        case Token::EXP10:
            return pow(10, getArgument());
        case Token::SQRT:
            arg = getArgument();
            if (arg < 0) {
                throw RuntimeError{"attempting to take square root of a negative number."};
            }
            return sqrt(arg);
        default:
            throw SyntaxError{"invalid expression."};
    }
}

void Parser::checkDomain(double x, double y) {
    if (x >= 0) {
        return;
    }

    double power = abs(y);
    if (power <= 0 || power >= 1) {
        return;
    }

    throw RuntimeError{"attempting to take root of a negative number."};
}

double Parser::getArgument() {
    lexer_ptr->advance();
    if (lexer_ptr->getCurrentToken() != Token::LPAREN) {
        throw SyntaxError{"missing '(' after function name."};
    }
    lexer_ptr->advance();
    double arg = addExpr();
    if (lexer_ptr->getCurrentToken() != Token::RPAREN) {
        throw SyntaxError{"missing ')' after function argument."};
    }
    lexer_ptr->advance();
    return arg;
}
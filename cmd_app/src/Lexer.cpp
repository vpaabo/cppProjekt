#include <iostream>
#include <string>
#include <vector>
#include "../include/Token.h"
#include "../include/Lexer.h"

using namespace std;

StringReader::StringReader(string s) : input(s), position(0) {}

int StringReader::read()
{
    if (position >= (int)input.length())
    {
        return -1;
    }
    return input[position++];
}

int StringReader::peek()
{
    if (position >= (int)input.length())
    {
        return -1;
    }
    return input[position];
}

void StringReader::close()
{
    input = "";
    position = 0;
}

Lexer::Lexer(StringReader _sr) : reader{_sr} {}

vector<Token> Lexer::readAllTokens()
{
    vector<Token> tokens{};

    Token token;
    do
    {
        token = readNextToken();
        tokens.push_back(token);
    } while (token.getType() != EOFRFR);
    return tokens;
}

void Lexer::consume()
{
    if (current == TERMINATOR)
    {
        throw runtime_error("Reading passed terminator!");
    }
    read();
    pos++;
}
char Lexer::peek()
{
    if (current == START)
        read();
    return current;
}
void Lexer::read()
{
    try
    {
        int i = reader.read();
        current = (i == -1) ? TERMINATOR : static_cast<char>(i);
    }
    catch (ios_base::failure &e)
    {
        throw runtime_error("IO Exception: " + string(e.what()));
    }
}

Token Lexer::readNextToken()
{
    while (peek() != TERMINATOR)
    {
        if (isdigit(peek()))
        {
            return readInteger();
        }
        else if (isspace(peek()))
        {
            consume();
        }
        else if (peek() == '(')
        {
            consume();
            return singleCharToken(LPAREN);
        }
        else if (peek() == ')')
        {
            consume();
            return singleCharToken(RPAREN);
        }
        else if (peek() == '+')
        {
            consume();
            return singleCharToken(PLUS);
        }
        else if (peek() == '-')
        {
            consume();
            return singleCharToken(MINUS);
        }
        else if (peek() == '*')
        {
            consume();
            return singleCharToken(TIMES);
        }
        else if (peek() == '/')
        {
            consume();
            return singleCharToken(DIV);
        }
        else
        {
            throw runtime_error("Unexpected symbol");
        }
    }
    return Token(EOFRFR, pos, 0);
}
Token Lexer::singleCharToken(Type type)
{
    Token t{type, pos - 1, 1};
    return t;
}
Token Lexer::readInteger()
{
    int result{peek() - '0'};
    consume();

    int initPos{pos};
    while (isdigit(peek()))
    {
        result = 10 * result + peek() - '0';
        consume();
    }
    Token t{INTEGER, result, pos, pos - initPos};
    return t;
}

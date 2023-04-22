#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
#include <vector>
#include "Token.h"

using namespace std;

class StringReader
{
private:
    string input;
    int position;

public:
    StringReader(string s);

    int read();

    int peek();

    void close();
};

class Lexer
{
private:
    const char TERMINATOR = '\0';
    const char START = '\1';

    StringReader reader;
    char current = START;
    int pos = 0;

public:
    Lexer(StringReader _sr);

    vector<Token> readAllTokens();

    void consume();
    char peek();
    void read();

    Token readNextToken();
    Token singleCharToken(Type type);
    Token readInteger();
};

#endif
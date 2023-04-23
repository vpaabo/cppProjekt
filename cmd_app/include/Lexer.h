#ifndef LEXER_H
#define LEXER_H

#include <sstream>
#include <string>

#include "Token.h"
#include "Error.h"

using namespace std;

using LexicalError = Error<1>;

class Lexer {
    istream* input_ptr;                 // Input stream (i.e. stream of user-inputted matematical expression)
    Token currentToken;
    string currentTokenText;
    string tokenBuffer;             // The text of the token that getToken() found

    void init();                    // Common method for constructors
    Token getToken();               // Turns characters from input into tokens

public:
    explicit Lexer(istream& is);
    explicit Lexer(istream* is_ptr);

    // Lexer goes with the parser, so it shouldn't be copied or moved

    Lexer(const Lexer&) = delete;
    Lexer& operator=(const Lexer&) = delete;

    Lexer(Lexer&&) = delete;
    Lexer& operator=(Lexer&&) = delete;

    ~Lexer() { delete input_ptr; };

    Token getCurrentToken() const { return currentToken; };
    string getTokenText() const { return currentTokenText; };

    void advance();                 // Read the next token from the input stream
};

#endif
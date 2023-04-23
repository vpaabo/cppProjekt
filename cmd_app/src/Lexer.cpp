#include "../include/Lexer.h"

Lexer::Lexer(istream& is) : input_ptr{&is} {
    init();
}

Lexer::Lexer(istream* is_ptr) : input_ptr{is_ptr} {
    init();
}

void Lexer::init() {
    currentToken = getToken();
    currentTokenText = tokenBuffer;
}

void Lexer::advance() {
    if (currentToken != Token::EOFRFR) {
        currentToken = getToken();
        currentTokenText = tokenBuffer;
    }
}

Token Lexer::getToken() {
    istream& input = *input_ptr;
    tokenBuffer.clear();
    char c = input.get();

    // Skip whitespace
    while (isspace(c)) {
        c = input.get();
    }

    // If input is empty, then we return EOF
    if (!input) {
        return Token::EOFRFR;
    }

    // Look for an identifier or function name
    if (isalpha(c)) {
        tokenBuffer = c;
        c = input.get();

        // Look for zero or more letters or digits
        while (isalnum(c)) {
            tokenBuffer += c;
            c = input.get();
        }

        // The current character doesn't belong to our identifier
        input.putback(c);

        // Check for a function name
        if (tokenBuffer == "ln") {
            return Token::LN;
        } else if (tokenBuffer == "exp") {
            return Token::EXP;
        } else if (tokenBuffer == "log") {
            return Token::LOG;
        } else if (tokenBuffer == "exp10") {
            return Token::EXP10;
        } else if (tokenBuffer == "sqrt") {
            return Token::SQRT;
        }

        // If it doesn't match any function, then it must be an identifier (e.g. pi or e)
        return Token::ID;
    }

    // Look for a digit
    if (isdigit(c)) {
        tokenBuffer = c;
        c = input.get();

        // Look for more digits
        while(isdigit(c)) {
            tokenBuffer += c;
            c = input.get();
        }

        // Look for a decimal point. Can be followed by zero or more digits
        if (c == '.') {
            tokenBuffer += c;
            c = input.get();

            while (isdigit(c)) {
                tokenBuffer += c;
                c = input.get();
            }
        }

        input.putback(c);
        return Token::NUMBER;
    }

    // Number can start with a decimal point too
    if (c == '.') {
        tokenBuffer = c;
        c = input.get();

        // If number starts with a decimal point, then it must be followed by a digit
        if (!isdigit(c)) {
            throw LexicalError{tokenBuffer += c};
        }

        while (isdigit(c)) {
            tokenBuffer += c;
            c = input.get();
        }

        input.putback(c);
        return Token::NUMBER;
    }

    // Check for one-character operator
    tokenBuffer = c;
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '^':
        case '%':
            return Token(c);
    }

    // Anything else is an error.
    throw LexicalError{tokenBuffer};
}
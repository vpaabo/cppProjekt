#ifndef TOKEN_H
#define TOKEN_H

enum class Token {
    ID, NUMBER, LN, EXP, LOG, EXP10, SQRT, PLUS='+', 
    MINUS='-', MUL='*', DIV='/', LPAREN='(',
    RPAREN=')', POW='^', MOD='%', EOFRFR=-1
};

#endif
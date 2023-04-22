#include <iostream>
#include <string>
#include <cmath>

#include "include/Token.h"
#include "include/Lexer.h"

using namespace std;

int main(int argc, char const *argv[])
{
    string s{"51+(3/200-4)*7"};
    StringReader stringReader{s};
    Lexer lexer{stringReader};

    vector<Token> tokens = lexer.readAllTokens();

    cout << s << "\n";
    for (Token t : tokens){
        cout << t << ", ";
    }

    return 0;
}

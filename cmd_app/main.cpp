#include <iostream>

#include "include/Parser.h"

int main()
{
    Parser parser;
    string s{"51.3+(3/200-4)*7"};
    
    try {
        cout << parser(s) << '\n';
    } catch (const LexicalError& e) {
        cerr << "Lexical error: " << e << '\n';
    } catch (const SyntaxError& e) {
        cerr << "Syntax error: " << e << '\n';
    } catch (const RuntimeError& e) {
        cerr << "Runtime error: " << e << '\n';
    }
}

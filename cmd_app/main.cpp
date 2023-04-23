#include <iostream>

#include "include/Parser.h"

int main()
{
    Parser parser;

    cout.precision(12);

    cout << "Insert mathematical expression or type 'quit':\n"; 
    
    while (cin) {
        string s;
        getline(cin, s);
        if (!cin || s == "quit") break;
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
}

#include "func.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    
    string expr;
    cout << "Sisesta matemaatiline avaldis:\n";
    cin >> expr;
    //cout << expr << "\n";
    Parser parser{expr};

    cout << "Avaldise v22rtus: " << parser.expression() << "\n";
    
    return 0;
}

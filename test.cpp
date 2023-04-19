#include <iostream>
using namespace std;

int main(){

    int kala{1};

    int* pkala = &kala;
    int** ppkala = &pkala;
    int*** pppkala = &ppkala;
    cout << kala << " : " << pkala << " : " << ppkala << " : " << pppkala << "\n";
    cout << &kala << " : " << &pkala << " : " << &ppkala << " : " << &pppkala << "\n";

}
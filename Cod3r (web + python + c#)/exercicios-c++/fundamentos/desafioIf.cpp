#include <iostream>
using namespace std;

int main() {
    cout << "DESAFIO IF" << endl;
    int num1, num2, num3;

    cout << endl << "Digite o Primeiro Número: ";
    cin >> num1;
    
    cout << endl << "Digite o Segundo Número: ";
    cin >> num2;

    cout << endl << "Digite o Terceiro Número: ";
    cin >> num3;

    if ((num1 >= num2) && (num1 >= num3)){
        cout << "Maior número = " << num1 << endl;
    } else if ((num2 >= num1) && (num2 >= num3)){
        cout << "Maior número = " << num2 << endl;
    } else {
        cout << "Maior número = " << num3 << endl;
    }
    
    return 0;
}
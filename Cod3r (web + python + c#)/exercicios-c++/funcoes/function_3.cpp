#include <iostream>
using namespace std;

int max(int n1, int n2){
    return n1 >= n2 ? n1 : n2;
}

int main() {
    int a, b, c;
    cout << endl << "Digite o Primeiro Número: ";
    cin >> a;
    
    cout << endl << "Digite o Segundo Número: ";
    cin >> b;

    cout << endl << "Digite o Terceiro Número: ";
    cin >> c;

    cout << "Max Value: " << max(a, max(b,c)) << endl;
    return 0;
}
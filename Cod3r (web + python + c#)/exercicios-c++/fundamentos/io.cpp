#include <iostream>
using namespace std;

int main(){
    // insertion operator "<<":
    // saída padrão do sistema (tela)
    cout << "Hi!\n";
    cout << 3.14 << endl;

    int x = 3;
    cout << x << endl;
    cout << typeid(x).name() << endl;
    cout << typeid(3.14).name() << endl;
    cout << typeid("3.14").name() << endl;
    cout << typeid(true).name() << endl;

    // extraction operator ">>":
    // entrada padrão do sistema (teclado)
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Wat up, " + name << endl;

    return 0;
}
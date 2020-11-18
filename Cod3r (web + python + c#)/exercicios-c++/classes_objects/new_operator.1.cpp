/*
    "new" armazena a variável na memória Heap!

    Sempre que se armazena na HEAP, é preciso DELETAR manualmente!

    "delete" libera espaço na memória ou, caso seja um OBJETO, ele 
    chama o DESTRUTOR!
*/

#include <iostream>


int main() {

    int x = 5; // STACK

    int* y = new int(10); // HEAP => 4 bytes;

    std::cout << *y << " - " << y << std::endl;

    delete y; // free() + destrutor;

    std::cout << *y << " - " << y << std::endl;

    int* w = new int[100]; // HEAP => 4 bytes * 100 == 400 bytes;

    w[49] = 123;

    std::cout << w[49] << std::endl;

    delete[] w;

    return 0;
}
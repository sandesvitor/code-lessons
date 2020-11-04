#include <iostream>
using namespace std;

void sayHello(std::string name){
    cout << "Hello " << name << endl;
}

std::string returnHello(){
    return "Hi";
}

int main() {
    sayHello("Vitor");
    sayHello("Anna");

    std::string result = returnHello();
    printf("%s\n", result.c_str());
    return 0;
}
#include <iostream>
using namespace std;

int sum(int a, int b){
    return a + b + 10;
}

namespace calc 
{
    int sum(int a, int b){
        return a + b + 20;
    }
}

int main() {
    cout << "Fora do namespace \"calc\": " << sum(10, 20) << endl;
    cout << "Dentro do namespace \"calc\": " << calc::sum(10, 20) << endl;
    return 0;
}

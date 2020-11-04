#include <iostream>
using namespace std;

class Entity
{
    public:
        int x;
    public:
        void Print(std::string name) const { std::cout << "Hello " << name << std::endl; }
};

int main() {

    Entity e;
    e.Print("Vitor");

    Entity* ptr = &e;
    Entity& entity = *ptr;
    entity.Print("Anna");
    (*ptr).Print("Marcha");

    // The arrow operator just make the "dereference" from the pointer!
    ptr->Print("Arrow Operator!");
    ptr->x = 100;
    cout << ptr->x << endl;

    return 0;
}
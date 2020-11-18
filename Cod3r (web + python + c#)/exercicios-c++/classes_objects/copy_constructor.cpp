#include <iostream>

class Player
{
public:
    std::string name;
    int health;

    Player(std::string n, int h = 100) : name(n), health(h) {}
    Player(const Player& p) : name(p.name), health(p.health) {
        std::cout << "copy constructor..." << std::endl;
    }
    ~Player(){ std::cout << "destructor" << std::endl; }
};

void printPlayer(const Player p){
    std::cout << p.name << " [" << p.health << "]" << std::endl; 
}


int main() {
    Player p("Monster");

    printPlayer(p);

    return 0;
}
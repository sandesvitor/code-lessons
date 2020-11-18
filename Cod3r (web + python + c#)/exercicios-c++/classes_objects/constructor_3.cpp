#include <iostream>


class Actor
{
public:
    std::string name;
    std::string email;

    // construtor default chamando outro construtor:
    Actor() : Actor("Anonymous", "-") {}
    

    Actor(std::string name, std::string email){
        // parênteses são aplicados para impedir a precedência
        // do ".", que se não tivesse o "*" estaria fazendo referência
        // a "this.name", e não só a "this"
        
        // (*this).name = name;
        // (*this).email = email;
        // ==

        this->name = name;
        this->email = email;
    }

    std::string toString(){
        return this->name + " [" + this->email + "]";
    }
};

int main() {
    Actor actor1;
    actor1.name = "Steve";
    actor1.email = "carell@office.com";
    std::cout << actor1.toString() << std::endl;

    Actor actor2("John", "dajdajd@dkadka.com");
    std::cout << actor2.toString() << std::endl;

    Actor actor3;
    std::cout << actor3.toString() << std::endl;


    return 0;
}
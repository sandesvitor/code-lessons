#include <iostream>


class User 
{
public:
    std::string name;
    std::string email;

    User(std::string _name, std::string _email){
        name = _name;
        email = _email;
    }

    User(){
        name = "";
        email = "";
    }

    std::string toString(){
        return name + " [" + email + "]";
    }
};

int main() {

    User user1;
    User user2("Vitor", "vitor@email.com");

    std::cout << "Hello, Friend!" << std::endl;
    return 0;
}
#include <iostream>


int main(int argc, char const *argv[])
{
    //argc ==> quantity of arguments the main() will receive!
    std::cout << argc << std::endl;
    std::cout << argv[0] << std::endl;
    if(argc >= 2){
        for (int i = 0; i < argc; i++){
            std::cout << argv[i] << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}

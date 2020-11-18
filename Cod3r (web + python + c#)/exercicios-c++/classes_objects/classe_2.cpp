#include <iostream>


class Product
{
public:
    std::string name;
    float price;
    float discount;

    float finalPrice(){
        return price * (1.0 - discount);
    }
};

int main() {
    Product p1;
    p1.name = "Notebook";
    p1.price = 1600.45;
    p1.discount = 0.15;

    std::cout << p1.name << std::endl;
    std::cout << p1.price << std::endl;
    std::cout << p1.discount << std::endl;
    std::cout << p1.finalPrice() << std::endl;
    

    // DIRECT LIST INITIALIZATION:
    Product p2 {"iPad", 899, 0.1};
    std::cout << p2.name << std::endl;
    std::cout << p2.price << std::endl;
    std::cout << p2.discount << std::endl;
    std::cout << p2.finalPrice() << std::endl;

    return 0;
}
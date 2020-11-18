#include <iostream>


class Person
{
public:
    std::string name;
    Person(std::string name){
        this->name = name;
        std::cout << "Hello! My name is " << this->name << std::endl;
    }
    ~Person(){
        std::cout << this->name << " is saying goodbye!" << std::endl;
    }
};

Person* createPerson(){
    Person p("Hanna");
    return &p;
}

int main() {
    Person* ptr1_p;
    {
        Person p1("Peter");
        ptr1_p = &p1;
    }

    // NÂO FAZER!
    // ESTAMOS ACESSANDO UM OBJETO FORA DO ESCOPO PARA O QUAL ELE FOI CRIADO!
    std::cout << ptr1_p->name /* == (*ptr_p).name */ << std::endl;

    Person* ptr2_p = createPerson();
    // vai acessar um espaço estranho de memória,
    // pq toda a memória associada à Stack já foi destruída!
    // (RESULTADO INESPERADO)
    std::cout << ptr2_p->name /* == (*ptr_p).name */ << std::endl;

    std::cout << "##### End of code #####" << std::endl;
    return 0;
}
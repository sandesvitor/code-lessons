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
    Person* p = new Person("Peter");
    return p;
}

void changePerson(Person& p){
    p.name += " Parker";
}

int main() {
    Person person1("Aunt May Parker");

    Person* person2 = new Person("John Wick");
    // se não destruir vai gerar MEMORY LEAK!

    /*
        "new" operator allocates memory on the heap
        and calls the constructor

        "delete" operator frees memory
        and calls the destructor
    */

    delete person2;

    // ALOCANDO APENAS UM ESPAÇO DE MEMÓRIA:
    Person* person3 = (Person*) malloc(sizeof(Person));
    // LIMPANDO O ESPAÇO DA MEMÓRIA:
    free(person3);

    Person* person4 = createPerson();
    changePerson(*person4);
    std::cout << person4->name << std::endl;
    delete person4;


    return 0;
}
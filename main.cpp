#include <iostream>
#include <memory>

class Toy{
    std::string name;
public:
    Toy(std::string _name): name(_name){};
    Toy(): name("SomeToy"){};
};



class Dog{
    std::string name;
    int age;
    std::shared_ptr<Toy> lovleyToy;
    
    Dog(std::string _name, std::shared_ptr<Toy> toy, int _age): lovleyToy(toy){
        if(_age >= 0 && _age < 30)
            age = _age;
    }

    Dog(): Dog("Snow", std::make_shared<Toy>("SomeToy"), 0){};
    Dog(std::string _name): Dog(_name, std::make_shared<Toy>("SomeToy"), 0){};
    Dog(int _age): Dog("Snow", std::make_shared<Toy>("SomeToy"), _age){}; 
    //функция скопировать игрушку другой собаки
    void copyLovlyToy(const Dog& oth){
        lovleyToy = oth.lovleyToy;
    }

};


int main(int, char**){
    std::cout << "Hello, from 31_1_smart_ptr!\n";

    std::shared_ptr<Toy> ball = std::make_shared<Toy>("Ball");
}


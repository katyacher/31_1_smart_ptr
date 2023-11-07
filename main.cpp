#include <iostream>
#include <string>
#include <memory>

class Toy{
    std::string name;
public:
    Toy(std::string _name): name(_name){};
    Toy(): name("SomeToy"){};

    std::string getName(){
       return name;
    }

    ~Toy(){
       std::cout << "Toy " << name << " was dropped " << std::endl;
    }
};


class Dog{
    std::string name;
    int age;
    std::shared_ptr<Toy> lovleyToy;
public:
    
    Dog(std::string _name, std::shared_ptr<Toy> toy, int _age): name(_name), lovleyToy(toy){
        if(_age >= 0 && _age < 30)
            age = _age;
    }

    Dog(): Dog("Snow", std::make_shared<Toy>("SomeToy"), 0){};
    Dog(std::string _name): Dog(_name, std::make_shared<Toy>("SomeToy"), 0){};
    Dog(int _age): Dog("Snow", std::make_shared<Toy>("SomeToy"), _age){}; 

    std::string getName(){
        return name;
    }

    void getToy(std::shared_ptr<Toy> toy){
        if(lovleyToy != nullptr && toy.get() == lovleyToy.get()){
            std::cout << this->getName() << " already have this toy" << std::endl;
            return;
        }

        if(toy.use_count() > 2) {
            std::cout << "Another dog is playing with this toy" << std::endl;
            return;
        } 

        lovleyToy = toy;
        std::cout << this->getName() << " get the toy " << toy->getName() << std::endl;
    };

    
    std::shared_ptr<Toy> dropToy(){
        std::shared_ptr<Toy> ptr = nullptr;
        if(lovleyToy != nullptr){
            ptr = lovleyToy;
            std::cout << this->getName() << " drop the toy " << lovleyToy->getName() << std::endl;
            lovleyToy = nullptr;
        } else {
            std::cout << "Nothing to drop." << std::endl;
        }
        return ptr;
    };

};


int main(int, char**){
    std::cout << "Hello, from 31_1_smart_ptr!\n";

    std::shared_ptr<Toy> ball = std::make_shared<Toy>("Ball");
    std::shared_ptr<Toy> bone = std::make_shared<Toy>("Bone");

    Dog a("Sharick", ball, 10);
    Dog b("Druzhok");

    std::cout << "Start the game" << std::endl;
    
    a.getToy(ball);
    b.getToy(ball);
    b.getToy(bone);
    b.getToy(a.dropToy());

    b.dropToy();
    b.dropToy();

    ball.reset();
    bone.reset();
   
}


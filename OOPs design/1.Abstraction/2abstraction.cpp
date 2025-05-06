// abstraction using interface (pure virtual functions)
#include<iostream>
using namespace std;

// Defining an interface
class Animal {
public:
  virtual void makeSound() = 0;   // pure virtual function
};

// implementing the interface in Dog class
class Dog : public Animal {
public:
  void makeSound() override {
    cout<<"Dog is Barking"<<endl;
  }
};

// implementing the interface in Cat class
class Cat : public Animal {
public:
  void makeSound() override {
    cout<<"Cat is Meowing"<<endl;
  }
};


int main(){
  Animal* myDog = new Dog();
  myDog->makeSound();
  Animal* myCat = new Cat();
  myCat->makeSound();

  delete myDog, myCat;
  return 0;
}
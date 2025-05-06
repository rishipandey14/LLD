// abstraction using abstract class
#include<iostream>
using namespace std;

// abstract class
class Vehichle {
protected:
  string brand;
public:
  Vehichle(string b) : brand(b) {}
  virtual void start() = 0;   // pure virtual function
  void displayBrand() {
    cout<<"Brand : "<<brand<<endl;
  }
};

// subClass implementing the abstract method
class Car : public Vehichle {
public:
  Car(string b) : Vehichle(b) {}
  void start() override {
    cout<<"Car is Starting..."<<endl;
  }
};


int main(){
  Vehichle* myCar = new Car("Toyota");
  myCar->displayBrand();
  myCar->start();
  delete myCar;
  return 0;
}
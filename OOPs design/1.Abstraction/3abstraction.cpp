// payment system with abstraction

#include<iostream>
using namespace std;

// abstract class
class Payment {
  protected:
    double amount;
  public:
    Payment(double amt) : amount(amt) {}
    virtual void pay() = 0;   // abstract method
};

// implementing payment methods
class CreditCardPayment : public Payment {
public:
  CreditCardPayment(double amt) : Payment(amt) {}
  void pay() override {
    cout<<"Paid " << amount << " Using Credit card"<<endl;
  }
};

class PaypalPayment : public Payment {
public:
  PaypalPayment(double amt) : Payment(amt) {}
  void pay() override {
    cout<<"Paid " << amount << " Using Paypal"<<endl;
  }
};


int main(){
  Payment* payment;

  payment = new CreditCardPayment(150.67);
  payment->pay();

  payment = new PaypalPayment(200.67);
  payment->pay();

  delete payment;
  return 0;
}
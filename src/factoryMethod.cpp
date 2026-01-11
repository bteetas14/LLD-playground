#include <iostream>
using namespace std;

class Payment{
    public:
        virtual void pay(int amount) = 0;
        virtual ~Payment(){};
};

class BasicCardPayment : public Payment{
    public:
        void pay(int amt) override {
            cout << "\npaying using BasicCardPayment, amount " << amt << endl;
        }
};

class PremiumCardPayment : public Payment{
    public:
        void pay(int amt) override {
            cout << "\npaying using PremiumCardPayment, amount " << amt << endl;
        }
};

class BasicUpiPayment : public Payment{
    public:
        void pay(int amt) override {
            cout << "\npaying using BasicUpiPayment, amount " << amt << endl;
        }
};

class PremiumUpiPayment : public Payment{
    public:
        void pay(int amt) override {
            cout << "\npaying using PremiumUpiPayment, amount " << amt << endl;
        }
};

class Paymentfactory{
    public:
        virtual Payment* createPaymentObj(string& tier) = 0;
        virtual ~Paymentfactory(){};
};

class CardPayment : public Paymentfactory{
    public:
        Payment* createPaymentObj(string& tier) override {
            if(tier=="basic"){
                return new BasicCardPayment();
            }
            else if(tier=="premium"){
                return new PremiumCardPayment();
            }
            else{
                cout << "\ninvalid CardPayment tier" << endl;
                return nullptr;
            }
        }
};

class UpiPayment : public Paymentfactory{
    public:
        Payment* createPaymentObj(string& tier) override {
            if(tier=="basic"){
                return new BasicUpiPayment();
            }
            else if(tier=="premium"){
                return new PremiumUpiPayment();
            }
            else{
                cout << "\ninvalid UpiPayment tier" << endl;
                return nullptr;
            }
        }
};

int main(){

    Paymentfactory* myfactory = new CardPayment();

    string tier = "premium";

    Payment* pObj = myfactory->createPaymentObj(tier);

    pObj->pay(110);

    return 0;
}
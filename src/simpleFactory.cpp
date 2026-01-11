#include <iostream>
using namespace std;

class Burger{
    public:
        virtual void prepare() = 0;
        virtual ~Burger(){};
};

class SmallBurger : public Burger{
    public:
        void prepare() override {
            cout << "\nthis is small burger" << endl;
        }
};

class MediumBurger : public Burger{
    public:
        void prepare() override {
            cout << "\nthis is medium burger" << endl;
        }
};

class BigBurger : public Burger{
    public:
        void prepare() override {
            cout << "\nthis is bug burger" << endl;
        }
};

class BurgerFactory{
    public:
        BurgerFactory(){
            cout << "\nburger factory is object is created!" << endl;
        }

        Burger* createBurger(string &type){
            if(type=="small"){
                return new SmallBurger();
            }
            else if(type=="medium"){
                return new MediumBurger();
            }
            else if(type=="big"){
                return new BigBurger();
            }
            else{
                cout << "\nInvalid burger type!" << endl;
                return nullptr;
            }
        }
};

int main(){

    string type = "medium";

    BurgerFactory* burgerFact = new BurgerFactory();

    Burger* burger = burgerFact->createBurger(type);

    burger->prepare();

    return 0;
}

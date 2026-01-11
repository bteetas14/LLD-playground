#include <iostream> 
using namespace std;

class Burger{
    public: 
        string bun;
        string patty;
        bool cheese = false;
        bool lettuce = false;
        bool sauce = false;

        Burger(string type){
            cout << "\n" << type << " burger created!" << endl;
        }

        void show(){
            cout << "\nBurger details:" << endl;
            cout << "\nbun: " << bun << endl;
            cout << "\npatty: " << patty << endl;
            cout << "\ncheese: " << (cheese ? "yes" : "no") << endl;
            cout << "\nlettuce: " << (lettuce ? "yes" : "no") << endl;
            cout << "\nsauce: " << (sauce ? "yes" : "no") << endl;
        }
};

class BurgerBuilder{
    public:
        BurgerBuilder(){}

        virtual void addBun(string b) = 0;
        virtual void addPatty(string p) = 0;
        virtual void addCheese(bool c) = 0;
        virtual void addLettuce(bool l) = 0;
        virtual void addSauce(bool s) = 0;
        virtual Burger* getBurger() = 0;
        virtual ~BurgerBuilder(){};
};

class KingBurgerBuilder : public BurgerBuilder{
        Burger* burger;
    public:
        KingBurgerBuilder(){
            burger = new Burger("king");
        }

        void addBun(string b) override {
            burger->bun = b;
        }
        void addPatty(string p) override {
            burger->patty = p;
        }
        void addCheese(bool c) override {
            burger->cheese = c;
        }
        void addLettuce(bool l) override {
            burger->lettuce = l;
        }
        void addSauce(bool s) override {
            burger->sauce = s;
        }
        Burger* getBurger() override {
            return burger;
        }
};

class ClassicBurgerBuilder : public BurgerBuilder{
        Burger* burger;
    public:
        ClassicBurgerBuilder(){
            burger = new Burger("classic");
        }

        void addBun(string b) override {
            burger->bun = b;
        }
        void addPatty(string p) override {
            burger->patty = p;
        }
        void addCheese(bool c) override {
            burger->cheese = c;
        }
        void addLettuce(bool l) override {
            burger->lettuce = l;
        }
        void addSauce(bool s) override {
            burger->sauce = s;
        }
        Burger* getBurger() override {
            return burger;
        }
};


int main(){
    
    BurgerBuilder* builder = new KingBurgerBuilder();

    builder->addBun("Garlic bun");
    builder->addPatty("Beef patty");
    builder->addLettuce(true);
    builder->addSauce(true);

    Burger* b = builder->getBurger();
    b->show();

    return 0;
}
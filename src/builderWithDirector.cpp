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

        virtual void addBun() = 0;
        virtual void addPatty() = 0;
        virtual void addCheese() = 0;
        virtual void addLettuce() = 0;
        virtual void addSauce() = 0;
        virtual Burger* getBurger() = 0;
        virtual ~BurgerBuilder(){};
};

class KingBurgerBuilder : public BurgerBuilder{
        Burger* burger;
    public:
        KingBurgerBuilder(){
            burger = new Burger("king");
        }

        void addBun() override {
            burger->bun = "Parmesan bun";
        }
        void addPatty() override {
            burger->patty = "chicken tandoori patty";
        }
        void addCheese() override {
            burger->cheese = true;
        }
        void addLettuce() override {
            burger->lettuce = true;
        }
        void addSauce() override {
            burger->sauce = true;
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

        void addBun() override {
            burger->bun = "Wheat bun";
        }
        void addPatty() override {
            burger->patty = "chicken bbq patty";
        }
        void addCheese() override {
            burger->cheese = false;
        }
        void addLettuce() override {
            burger->lettuce = true;
        }
        void addSauce() override {
            burger->sauce = true;
        }
        Burger* getBurger() override {
            return burger;
        }
};

class BurgerDirector{
    public:
        BurgerDirector(){
            cout << "\nDirector called." << endl;
        }

        void makeFullBurger(BurgerBuilder* builder){
            builder->addBun();
            builder->addPatty();
            builder->addCheese();
            builder->addLettuce();
            builder->addSauce();
        }

        void makeGoBurger(BurgerBuilder* builder){
            builder->addBun();
            builder->addPatty();
            builder->addSauce();
        }
};

int main(){
    
    BurgerDirector* director = new BurgerDirector();

    BurgerBuilder* builder = new KingBurgerBuilder();
    director->makeGoBurger(builder);

    Burger* b = builder->getBurger();
    b->show();

    return 0;
}
#include <iostream>
using namespace std;

class Engine{
    public:
        virtual void use() = 0;
        virtual ~Engine(){};
};

class Tyre{
    public:
        virtual void use() = 0;
        virtual ~Tyre(){};
};

class Seat{
    public:
        virtual void use() = 0;
        virtual ~Seat(){};
};

// India

class IndianEngine : public Engine{
    public:
        void use() override {
            cout << "\nusing Indian Engine." << endl;
        }
};

class IndianTyre : public Tyre{
    public:
        void use() override {
            cout << "\nusing Indian Tyre." << endl;
        }
};

class IndianSeats : public Seat{
    public:
        void use() override {
            cout << "\nusing Indian Seats." << endl;
        }
};

// germany

class GermanEngine : public Engine{
    public:
        void use() override {
            cout << "\nusing German Engine." << endl;
        }
};

class GermanTyre : public Tyre{
    public:
        void use() override {
            cout << "\nusing German Tyre." << endl;
        }
};

class GermanSeats : public Seat{
    public:
        void use() override {
            cout << "\nusing German Seats." << endl;
        }
};

class CountryComponentFactory{
    public:
        virtual Engine* createEngine() = 0;
        virtual Tyre* createTyre() = 0;
        virtual Seat* createSeat() = 0;
        virtual ~CountryComponentFactory(){};
};

class IndiaComponentFactory : public CountryComponentFactory{
    public:
        IndiaComponentFactory(){
            cout << "\nindian factory being called." << endl;
        }

        Engine* createEngine() override {
            return new IndianEngine();
        }

        Tyre* createTyre() override {
            return new IndianTyre();
        }

        Seat* createSeat() override {
            return new IndianSeats();
        }
};

class GermanyComponentFactory : public CountryComponentFactory{
    public:
        GermanyComponentFactory(){
            cout << "\ngerman factory being called." << endl;
        }

        Engine* createEngine() override {
            return new GermanEngine();
        }

        Tyre* createTyre() override {
            return new GermanTyre();
        }

        Seat* createSeat() override {
            return new GermanSeats();
        }
};

int main(){

    CountryComponentFactory* countryFactory = new GermanyComponentFactory();

    Engine* engineObj = countryFactory->createEngine();
    Tyre* tyreObj = countryFactory->createTyre();

    engineObj->use();
    tyreObj->use();

    return 0;
}
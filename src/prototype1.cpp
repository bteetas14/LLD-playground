#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Prototype{
    public:
        virtual ~Prototype() = default;

        virtual unique_ptr<Prototype> clone() const = 0;

        virtual void show() const = 0;
};

class ConcretePrototype : public Prototype{
    private:
        string name;
        int *value;

    public:
        ConcretePrototype(string n, int v){
            name = n;
            value = new int(v);
        }

        ConcretePrototype(const ConcretePrototype& other){
            name = other.name;
            value = new int(*other.value);
        }

        ~ConcretePrototype(){
            delete value;
        }

        unique_ptr<Prototype> clone() const override {
            return make_unique<ConcretePrototype>(*this);
        }

        void setValue(int v){
            *value = v;
        }

        void show() const override {
            cout << "Object: " << name << ", value = " << *value << endl;
        }
};

int main(){

    unique_ptr<Prototype> original = make_unique<ConcretePrototype>("org_teetas", 10);

    unique_ptr<Prototype> copy = original->clone();

    cout << "Before modification: " << endl;
    original->show();
    copy->show();

    static_cast<ConcretePrototype*>(copy.get())->setValue(12345);

    cout << "After modification: " << endl;
    original->show();
    copy->show();

    return 0;

}
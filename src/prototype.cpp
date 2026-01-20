#include <iostream>
#include <memory>
#include <string>
using namespace std;

/*
 Prototype base class
 Declares clone() so objects can copy themselves
*/
class Prototype {
public:
    virtual ~Prototype() = default;

    // Core of Prototype pattern
    virtual unique_ptr<Prototype> clone() const = 0;

    virtual void show() const = 0;
};

/*
 Concrete Prototype
 Demonstrates deep copy behavior
*/
class ConcretePrototype : public Prototype {
private:
    string name;
    int* value;   // dynamically allocated to show deep copy

public:
    // Normal constructor
    ConcretePrototype(string n, int v)
        : name(n), value(new int(v)) {}

    // Copy constructor (deep copy)
    ConcretePrototype(const ConcretePrototype& other)
        : name(other.name), value(new int(*other.value)) {}

    // Destructor
    ~ConcretePrototype() {
        delete value;
    }

    // Clone implementation
    unique_ptr<Prototype> clone() const override {
        return make_unique<ConcretePrototype>(*this);
    }

    void setValue(int v) {
        *value = v;
    }

    void show() const override {
        cout << "Object: " << name << ", value = " << *value << endl;
    }
};

/*
 Client code
*/
int main() {
    // Original object (expensive creation assumed)
    unique_ptr<Prototype> original =
        make_unique<ConcretePrototype>("Original", 100);

    // Clone the object
    unique_ptr<Prototype> copy = original->clone();

    cout << "Before modification:" << endl;
    original->show();
    copy->show();

    // Modify the cloned object
    static_cast<ConcretePrototype*>(copy.get())->setValue(20330);

    cout << "\nAfter modifying clone:" << endl;
    original->show();
    copy->show();

    return 0;
}

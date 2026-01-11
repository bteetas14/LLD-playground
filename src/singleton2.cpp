#include <iostream>
using namespace std;

class Singleton{
    private:
        static Singleton* instance;
        static mutex mtx;

        Singleton(){ 
            cout << "\nconstructorr made.\n";
        }
    
    public:
        static Singleton* getInstance(){
            if(instance == NULL){
                lock_guard<mutex> lock(mtx); // lock for thread safety
                if(instance == NULL){
                    instance = new Singleton(); 
                }
            }
            return instance;
        }
};

// initialize static members
Singleton* Singleton::instance = NULL;
mutex Singleton::mtx;

// Singleton* Singleton::instance = new Singleton(); // eager initialization

int main(){

    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;

    return 0;
}
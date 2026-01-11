#include <iostream>
using namespace std;

class UIComponent{
    public:
        virtual void use() = 0;
        virtual ~UIComponent(){};
};

class ButtonMacOSUI : public UIComponent{
    public:
        void use() override {
            cout << "\nusing button for macOS in UI." << endl;
        }
};

class CheckboxMacOSUI : public UIComponent{
    public: 
        void use() override {
            cout << "\nusing checkbox for macOS in UI." << endl;
        }
};

class MenuMacOSUI : public UIComponent{
    public:
        void use() override {
            cout << "\nusing menu for macOS in UI." << endl;
        }
};

class ButtonWindowsUI : public UIComponent{
    public:
        void use() override {
            cout << "\nusing button for Windows in UI." << endl;
        }
};

class CheckboxWindowsUI : public UIComponent{
    public:
        void use() override {
            cout << "\nusing checkbox for Windows in UI." << endl;
        }
};

class MenuWindowsUI : public UIComponent{
    public: 
        void use() override {
            cout << "\nusing menu for Windows in UI." << endl;
        }
};

class OperatingSystemFactory{
    public:
        virtual UIComponent* createComponent(string& comp) = 0;
        virtual ~OperatingSystemFactory(){};
};

class WindowsFactory : public OperatingSystemFactory{
    public:
        UIComponent* createComponent(string& comp) override {
            if(comp=="button"){
                return new ButtonWindowsUI();
            }
            else if(comp=="checkbox"){
                return new CheckboxWindowsUI;
            }
            else if(comp=="menu"){
                return new MenuWindowsUI();
            }
            else{
                cout << "\ninvalid windows UI component type." << endl;
                return nullptr;
            }
        }
};

class MacOSFactory : public OperatingSystemFactory{
    public:
        UIComponent* createComponent(string& comp) override {
            if(comp=="button"){
                return new ButtonMacOSUI();
            }
            else if(comp=="checkbox"){
                return new CheckboxMacOSUI();
            }
            else if(comp=="menu"){
                return new MenuMacOSUI();
            }
            else{
                cout << "\ninvalid macOS UI component type." << endl;
                return nullptr;
            }
        }
};

int main(){

    OperatingSystemFactory* OSFactory = new MacOSFactory();

    string button = "button";

    UIComponent* macOSButton = OSFactory->createComponent(button);

    macOSButton->use();

    return 0;
}


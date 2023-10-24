// Код програми 10.8. Демонстрація механізму використання оператора dynamic_cast замість оператора typeid

#include <iostream>
#include <cstdlib>

using namespace std;

class Base {                    // Оголошення базового класу
public:
    virtual void fun() {}
};

class Derived : public Base {   // Оголошення похідного класу
public:
    void derivedOnly() { cout << "Це об'єкт класу Derived" << endl; }
};

int main() {
    system("chcp 65001");
    Base* basePtr;
    Base baseObject;
    Derived* derivedPtr;
    Derived derivedObject;

    // Використання оператора typeid
    basePtr = &baseObject;      // Присвоєння вказівнику адреси об'єкта базового класу
    if (typeid(*basePtr) == typeid(Derived)) {
        derivedPtr = (Derived*) basePtr;
        derivedPtr->derivedOnly();
    } else
        cout << "Операцiї приведення об'єкта типу Base до типу Derived не здiйснено" << endl;

    basePtr = &derivedObject;   // Присвоєння вказвнику адреси об'єкта похідного класу
    if (typeid(*basePtr) == typeid(Derived)) {
        derivedPtr = (Derived*) basePtr;
        derivedPtr->derivedOnly();
    } else
        cout << "Помилка, приведення типу має бути реалiзовано!" << endl;

    // Використання оператора dynamic_cast
    basePtr = &baseObject;      // Присвоєння вказівнику адреси об'єкта базового класу
    derivedPtr = dynamic_cast<Derived*> (basePtr);

    if (derivedPtr) derivedPtr->derivedOnly();
    else
        cout << "Операцiї приведення об'єкта типу Base до типу Derived не здiйснено" << endl;

    basePtr = &derivedObject;   // Присвоєння вказівнику адреси об'єкта похідного класу
    derivedPtr = dynamic_cast<Derived*> (basePtr);
    if (derivedPtr) derivedPtr->derivedOnly();
    else
        cout << "Помилка, приведення типу має бути реалiзовано!" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

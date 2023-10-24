// Код програми 10.7. Демонстрація різних ситуацій застосування оператора dynamic_cast

#include <iostream>
#include <cstdlib>

using namespace std;

class Base {                    // Оголошення базового класу
public:
    virtual void fun() { cout << "У класi Base" << endl; }
    //. . .
};

class Derived : public Base {   // Оголошення похідного класу
public:
    void fun() { cout << "У класi Derived" << endl; }
};

int main() {
    system("chcp 65001");
    Base* basePtr;
    Base baseObject;
    Derived* derivedPtr;
    Derived derivedObject;

    derivedPtr = dynamic_cast<Derived*> (&derivedObject);
    if (derivedPtr) {
        cout << "Приведення типiв (з Derived* у Derived*) реалiзовано" << endl;
        derivedPtr->fun();
    } else
        cout << "Помилка" << endl;
    cout << endl;

    basePtr = dynamic_cast<Base*> (&derivedObject);
    if (basePtr) {
        cout << "Приведення типiв (з Derived* у Base*) реалiзовано" << endl;
        basePtr->fun();
    } else
        cout << "Помилка" << endl;
    cout << endl;

    basePtr = dynamic_cast<Base*> (&baseObject);
    if (basePtr) {
        cout << "Приведення типiв (з Base* у Base*) реалiзовано" << endl;
        basePtr->fun();
    } else
        cout << "Помилка" << endl;
    cout << endl;

    derivedPtr = dynamic_cast<Derived*> (&baseObject);
    if (derivedPtr) cout << "Помилка" << endl;
    else
        cout << "Приведення типiв (з Base* у Derived*) не реалiзовано" << endl;
    cout << endl;

    basePtr = &derivedObject;   // Присвоєння вказівнику адреси об'єкта похідного класу
    // basePtr вказує на об'єкт класу Derived
    derivedPtr = dynamic_cast<Derived*> (basePtr);
    if (derivedPtr) {
        cout << "Приведення basePtr до типу Derived*\n реалiзовано, оскiльки basePtr дійсно\n"
             << "вказує на об'єкт класу Derived" << endl;
        derivedPtr->fun();
    } else
        cout << "Помилка" << endl;
    cout << endl;

    basePtr = &baseObject;      // Присвоєння вказівнику адреси об'єкта базового класу
    // basePtr вказує на об'єкт класу Base
    derivedPtr = dynamic_cast<Derived*> (basePtr);
    if (derivedPtr)
        cout << "Помилка";
    else {
        cout << "Тепер приведення basePtr до типу Derived*\n не реалiзовано, оскiльки basePtr\n"
             << "насправдi вказує на об'єкт класу Base" << endl;
    }
    cout << endl;

    derivedPtr = &derivedObject;// Присвоєння вказівнику адреси об'єкта похідного класу
    // derivedPtr вказує на об'єкт класу Derived
    basePtr = dynamic_cast<Base*> (derivedPtr);
    if (basePtr) {
        cout << "Приведення derivedPtr до типу Base* реалiзовано" << endl;
        basePtr->fun();
    } else
        cout << "Помилка" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

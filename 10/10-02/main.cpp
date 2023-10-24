// Код програми 10.2. Демонстрація механізму застосування оператора typeid до ієрархії поліморфних класів

#include <iostream>
#include <cstdlib>

using namespace std;

class Base {                    // Оголошення базового класу
    virtual void fun() {        // Робимо клас Base поліморфним
        //. . .
    };
};

class DerivedA : public Base {
    //. . .
};

class DerivedB : public Base {
    //. . .
};

int main() {
    system("chcp 65001");
    Base* basePtr;
    Base baseObject;            // Створення об'єкта базового класу
    DerivedA ObjA;              // Створення об'єкта похідного класу
    DerivedB ObjB;              // Створення об'єкта похідного класу

    basePtr = &baseObject;
    cout << "Змiнна basePtr вказує на об'єкт типу ";
    cout << typeid(*basePtr).name() << endl;

    basePtr = &ObjA;
    cout << "Змiнна basePtr вказує на об'єкт типу ";
    cout << typeid(*basePtr).name() << endl;

    basePtr = &ObjB;
    cout << "Змiнна basePtr вказує на об'єкт типу ";
    cout << typeid(*basePtr).name() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

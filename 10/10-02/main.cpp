//Код програми 10.2. Демонстрація механізму застосування оператора typeid до ієрархії поліморфних класів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <typeinfo> 		// Для динамічної ідентифікації типів

using namespace std; 			// Використання стандартного простору імен

// Оголошення базового класу
class Base {
    virtual void Fun() {}; // Робимо клас Base поліморфним
    //. . .
};

class DerivedA: public Base {
    //. . .
};

class DerivedB: public Base {
    //. . .
};
int main()
{
    Base *p, baseob;
    DerivedA ObjA; 		// Створення об'єкта класу
    DerivedB ObjB; 		// Створення об'єкта класу
    p = &baseob;
    cout << "Змiнна p вказує на об'єкт типу ";
    cout << typeid(*p).name() << endl;

    p = &ObjA;
    cout << "Змiнна p вказує на об'єкт типу ";
    cout << typeid(*p).name() << endl;

    p = &ObjB;
    cout << "Змiнна p вказує на об'єкт типу ";
    cout << typeid(*p).name() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

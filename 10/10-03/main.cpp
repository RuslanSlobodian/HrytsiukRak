//Код програми 10.3. Демонстрація механізму застосування оператора typeidдо посилального параметра

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <typeinfo> 		// Для динамічної ідентифікації типів

using namespace std; 			// Використання стандартного простору імен

// Оголошення базового класу
class Base {
    virtual void Fun() {; // робимо клас Base поліморфним
                        //. . .
                       };
};
class DerivedA: public Base {
    //. . .
};
class DerivedB: public Base {
    //. . .
};

// Демонструємо застосування оператора typeid до посилального  параметра.
void WhatType(Base &obj)
{
    cout << "Параметр obj посилається на об'єкт типу ";
    cout << typeid(obj).name() << endl;
}
int main()
{
    int c;

    Base baseob;
    DerivedA ObjA; 		// Створення об'єкта класу
    DerivedB ObjB; 		// Створення об'єкта классу

    WhatType(baseob);
    WhatType(ObjA);
    WhatType(ObjB);

    //system("PAUSE");
    return EXIT_SUCCESS;
}

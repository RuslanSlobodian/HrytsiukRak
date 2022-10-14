//Код програми 5.18. Демонстрація механізму застосування віртуальних базових класів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class BaseClass { // Оголошення базового класу
public:
    int c;
};

// Клас derivedA успадковує клас baseClass як віртуальний.
class derivedA : virtual public BaseClass {
public:
    int d;
};

// Клас derivedB успадковує клас baseClass як віртуальний.
class derivedB : virtual public BaseClass {
public:
    int f;
};

/* Клас derivedC успадковує обидва класи derivedA і derivedB.
    Цього разу вінмістить тільки одну копіюкласу baseClass. */
class derivedC : public derivedA, public derivedB {
public:
    int sum;
};

int main()
{
    derivedC ObjC;
    ObjC.c = 10;		 // Тепер неоднозначності немає.
    ObjC.d = 20;
    ObjC.f = 30;

    // Тепер неоднозначності немає.
    ObjC.sum = ObjC.c + ObjC.d + ObjC.f;

    // Тепер неоднозначності немає.
    cout << ObjC.c << " ";

    cout << ObjC.d << " " << ObjC.f << " ";
    cout << ObjC.sum;


    //system("PAUSE");
    return EXIT_SUCCESS;
}

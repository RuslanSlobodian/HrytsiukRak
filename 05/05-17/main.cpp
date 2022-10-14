//Код програми 5.17. Демонстраціямеханізму використання оператора дозволу контексту для вибору потрібного члена

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class BaseClass { // Оголошення базового класу
public:
    int c;
};

// Клас derivedA успадковує клас baseClass.
class derivedA : public BaseClass {
public:
    int d;
};

// Клас derivedB успадковує клас baseClass.
class derivedB : public BaseClass {
public:
    int f;
};

/* Клас derivedC успадковує обидва класи derivedA і derivedB.
    Це означає, що у класі derivedC існує двікопіїкласу baseClass! */
class derivedC : public derivedA, public derivedB {
public:
    int sum;
};

int main()
{
    derivedC ObjC;

    ObjC.derivedA::c = 10; // Контекст дозволений, використовується член c класу derivedA.
    ObjC.d = 20;
    ObjC.f = 30;

    // Контекст дозволений ітут.
    ObjC.sum = ObjC.derivedA::c + ObjC.d + ObjC.f;

    // Виникнення неоднозначності ліквідована ітут.
    cout << ObjC.derivedA::c << " ";
    cout << ObjC.d << " " << ObjC.f << " ";
    cout << ObjC.sum;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

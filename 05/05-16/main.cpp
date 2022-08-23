//Код програми 5.16. Демонстрація невизначеності під час успадкування декількох базових класів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class baseClass { // Оголошення базового класу
public:
    int c;
};

// Клас derivedA успадковує клас baseClass.
class derivedA : public baseClass {
public:
    int d;
};

// Клас derivedB успадковує клас baseClass.
class derivedB : public baseClass {
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
    ObjC.c = 10; // Це і є неоднозначність: який саме член c маємо на увазі???
    ObjC.d = 20;
    ObjC.f = 30;

    // Ітуттеж спостерігається неоднозначність з членом c.
    ObjC.sum = ObjC.c + ObjC.d + ObjC.f;
    // Ітуттеж неоднозначність з членом c.
    cout << ObjC.c << " ";
    cout << ObjC.d << " " << ObjC.f << " ";
    cout << ObjC.sum;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 5.15. Демонстрація механізму використання голошення доступу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class baseClass { // Оголошення базового класу
    int c; // private-член у класі baseClass
public:
    int d, f;
    void Set(int x) { c = x; }
    int Put() { return c; }
};
// Клас baseClass успадковується як private-клас.
class derived : private baseClass {
public:
    /* Наступнітри настанови перевизначають private-успадкування класу baseClass і відновлюють public-статус доступу для членів d, Set() і Put(). */

    // Змінна d стає знову public-членом a змінна f залишається закритим членом.
    baseClass::d;
    baseClass::Set(); // Функція Set() стає public-членом.
    baseClass::Put(); // Функція Put() стає public-членом.

    // baseClass::c; // Неправильно: неможна підвищувати рівень доступу
    int a; // public-член
};
int main()
{
    derived ObjD; // Створення об'єкта класу

    // ObjD.c = 10; // Неправильно, оскільки член c закритий у класі derived.
    ObjD.d = 20; // Допустимо, оскільки член d став відкритим у класі derived
    // ObjD.f = 30; // Неправильно, оскільки член f закритий у класі derived.
    ObjD.a = 40; // Допустимо, оскільки член a відкрито у класі derived.
    ObjD.Set(10);
    cout << ObjD.Put() << " " << ObjD.d << " " << ObjD.a;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

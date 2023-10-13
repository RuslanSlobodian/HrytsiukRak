// Код програми 5.15. Демонстрація механізму використання оголошення доступу

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class BaseClass {               // Оголошення базового класу
    int c;                      // private-член у класі BaseClass
public:
    int d;
    int f;

    void setC(int c) { this->c = c; }
    int getC() { return c; }
};

// Клас BaseClass успадковується як private-клас
class Derived : private BaseClass {
public:
    int a; // public-член

    /* Наступні три настанови перевизначають private-успадкування класу BaseClass
     * і відновлюють public-статус доступу для членів d, setC() і getC()  */

    // атрибут d стає знову public-членом, a атрибут f залишається закритим членом
    using BaseClass::d;
    using BaseClass::setC;      // Метод setC() стає public-членом
    using BaseClass::getC;      // Метод getC() стає public-членом

    //    using baseClass::c;   // Неправильно: не можна підвищувати рівень доступу
};

int main() {
    Derived object;             // Створення об'єкта класу

    // object.c = 10;           // Неправильно, оскільки атрибут c закритий у класі Derived
    object.d = 20;              // Допустимо, оскільки член d атрибут відкритим у класі Derived
    // object.f = 30;           // Неправильно, оскільки атрибут f закритий у класі Derived
    object.a = 40;              // Допустимо, оскільки атрибут a відкрито у класі Derived
    object.setC(10);
    cout << object.getC() << " " << object.d << " " << object.a;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

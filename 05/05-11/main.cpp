// Код програми 5.11. Демонстрація послідовності виконання конструкторів і деструкторів під час успадкування декількох базових класів

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class BaseA {                   // Оголошення базового класу BaseA
public:
    BaseA() { cout << "Створення об'єкта класу BaseA" << endl; }

    ~BaseA() { cout << "Руйнування об'єкта класу BaseA" << endl; }
};

class BaseB {                   // Оголошення базового класу BaseB
public:
    BaseB() { cout << "Створення об'єкта класу BaseB" << endl; }

    ~BaseB() { cout << "Руйнування об'єкта класу BaseB" << endl; }
};

// Оголошення похідного класу
class Derived : public BaseA, public BaseB {
public:
    Derived() { cout << "Створення об'єкта класу Derived" << endl; }

    ~Derived() { cout << "Руйнування об'єкта класу Derived" << endl; }
};

int main() {
    system("chcp 65001");
    Derived derived;            // Створення і руйнування об'єкта класу Derived

    //system("PAUSE");
    return EXIT_SUCCESS;
}

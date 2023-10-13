// Код програми 5.10. Демонстрація послідовності виконання конструкторів і деструкторівпри розширеної ієрархії класів

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class BaseClass {               // Оголошення базового класу
public:
    BaseClass() { cout << "Створення об'єкта класу BaseClass" << endl; }
    ~BaseClass() { cout << "Руйнування об'єкта класу BaseClass" << endl; }
};

// Оголошення похідного класу
class DerivedA : public BaseClass {
public:
    DerivedA() { cout << "Створення об'єкта класу DerivedA" << endl; }
    ~DerivedA() { cout << "Руйнування об'єкта класу DerivedA" << endl; }
};

// Оголошення похідного класу
class DerivedB : public DerivedA {
public:
    DerivedB() { cout << "Створення об'єкта класу DerivedB" << endl; }
    ~DerivedB() { cout << "Руйнування об'єкта класу DerivedB" << endl; }
};

int main() {
    system("chcp 65001");
    DerivedB derivedB;          // Створення і руйнування об'єкта derivedB

    //system("PAUSE");
    return EXIT_SUCCESS;
}

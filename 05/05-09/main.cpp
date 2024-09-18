// Код програми 5.9. Демонстрація послідовності виконання конструкторів і деструкторів

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class BaseClass {               // Оголошення базового класу
public:
    BaseClass() { cout << "Створення об'єкта класу BaseClass" << endl; }
    ~BaseClass() { cout << "Руйнування об'єкта класу BaseClass" << endl; }
};

// Оголошення похідного класу
class Derived : public BaseClass {
public:
    Derived() { cout << "Створення об'єкта класу Derived" << endl; }
    ~Derived() { cout << "Руйнування об'єкта класу Derived" << endl; }
};

int main() {
    system("chcp 65001");
    Derived object;             // Створення об'єкта класу
    // Ніяких дій, окрім створення і руйнування об'єкта object

    //system("PAUSE");
    return EXIT_SUCCESS;
}

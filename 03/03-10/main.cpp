/*
 * Код програми 3.10. Демонстрація механізму вирішення проблеми при передачі об'єктів функціям,
 * у яких динамічно виділяється та звільняється область пам'яті
 */

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
    int* p;
public:
    MyClass(int c) {
        p = new int;
        *p = c;
        cout << "Видiлення p-пам'ятi звичайним конструктором" << endl;
    }

    ~MyClass() {
        delete p;
        cout << "Звiльнення p-пам'ятi" << endl;
    }

    int getData() { return *p; }
};

// Ця функція НЕ створює проблем
void function(MyClass& object) {// Передача об'єкта за посиланням
    cout << "*p = " << object.getData() << endl;
}

int main() {
    system("chcp 65001");
    MyClass objectA(10);        // Створення об'єкта класу
    function(objectA);

    //system("PAUSE");
    return EXIT_SUCCESS;
}

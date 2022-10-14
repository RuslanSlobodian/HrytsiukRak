/*
 * Код програми 3.9. Демонстрація механізму появи проблеми, яка виникає при
 * передачі об'єктів функціям, у яких динамічно виділяється та
 * звільняється область пам'яті
 */

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

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

// У процесі виконання цієї функції виникає проблема
void function(MyClass object) { // Звичайна передача об'єкта
    cout << "*p = " << object.getData() << endl;
}

int main() {
    MyClass objectA(10);        // Створення об'єкта класу
    function(objectA);

    //system("PAUSE");
    return EXIT_SUCCESS;
}

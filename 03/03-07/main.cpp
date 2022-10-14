// Код програми 3.7. Демонстрація механізму передачі об'єктів функціям

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
    int c;
public:
    MyClass() { c = 0; }
    void setC(int _c) { c = _c; }
    void show(string s) {
        cout << s << c << endl;
    }
};

void function(MyClass objectB) {// Визначення функції не члена класу
    objectB.show("t2 = ");      // Виведення числа 10
    objectB.setC(100);          // Встановлює тільки локальну копію
    objectB.show("t3 = ");      // Виведення числа 100
}

int main() {
    MyClass objectA;            // Створення об'єкта класу
    objectA.setC(10);
    objectA.show("t1 = ");      // Виведення числа 10
    function(objectA);          // Передача об'єкта у функцію не член класу
    objectA.show("t4 = ");      // Як і раніше, виводиться число 10

    //system("PAUSE");
    return EXIT_SUCCESS;
}

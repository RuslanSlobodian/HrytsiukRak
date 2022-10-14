// Код програми 3.8. Демонстрація механізму використання конструкторів, деструкторів при передачі об'єктів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
    int n;
public:
    MyClass(int _n) {
        n = _n;
        cout << "Створення об'єкта" << endl;
    }
    ~MyClass() {
        cout << "Руйнування об'єкта" << endl;
    }
    int getData() {
        return n;
    }
};

void function(MyClass object) {
    cout << "n = " << object.getData() << endl;
}

int main() {
    MyClass objectA(10);        // Створення об'єкта класу
    function(objectA);

    //system("PAUSE");
    return EXIT_SUCCESS;
}

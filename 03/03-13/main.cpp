// Код програми 3.13. Демонстрація механізму використання конструктора копії для ініціалізації одного об'єкта іншим

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
    int* p;
public:
    MyClass(int c) {            // Визначення звичайного конструктора
        p = new int;
        *p = c;
        cout << "Видiлення p-пам'ятi звичайним конструктором" << endl;
    }
    MyClass(const MyClass &sourceObject) { // Визначення конструктора копії
        p = new int;
        *p = *sourceObject.p;
        cout << "Видiлення p-пам'ятi конструктором копiї" << endl;
    }
    ~MyClass() {
        delete p;
        cout << "Звiльнення p-пам'ятi" << endl;
    }
};

int main() {
    MyClass objectA(10);        // Викликається звичайний конструктор
    MyClass objectB = objectA;  // Викликається конструктор копії

    //system("PAUSE");
    return EXIT_SUCCESS;
}

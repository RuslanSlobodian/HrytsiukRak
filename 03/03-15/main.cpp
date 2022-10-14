// Код програми 3.15. Демонстрація механізму використання конструктора копії для створення тимчасового об'єкта, що повертається функцією

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу

public:
    MyClass() {
        cout << "Звичайний конструктор" << endl;
    }
    MyClass(const MyClass& object) {
        cout << "Конструктор копiї" << endl;
    }
};

MyClass function() {
    MyClass objectB;            // Викликається звичайний конструктор
    return objectB;             // Опосередковано викликається конструктор копії
}

int main() {
    MyClass objectA;            // Викликається звичайний конструктор
    MyClass objectB(objectA);   // Викликається конструктор копії

    //system("PAUSE");
    return EXIT_SUCCESS;
}

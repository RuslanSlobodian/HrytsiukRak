// Код програми 3.14. Демонстрація механізму використання конструктора копії для передачі об'єкта функції

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
    // Визначення конструктора копії
    MyClass(const MyClass &object){
        p = new int;
        *p = *object.p;
        cout << "Видiлення p-пам'ятi конструктором копiї" << endl;
    }
    ~MyClass() {
        delete p;
        cout << "Звiльнення p-пам'ятi" << endl;
    }
    int getData() {
        return *p;
    }
};

// Ця функція приймає один об'єкт-параметр
void function(MyClass objectB) {
    cout << "*p = " << objectB.getData() << endl;
}

int main()
{
    MyClass objectA(10);        // Створення об'єкта класу
    function(objectA);

    //system("PAUSE");
    return EXIT_SUCCESS;
}

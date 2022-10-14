// Код програми 3.6. Демонстрація механізму присвоєння об'єктів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
    int a;
    int b;
public:
    MyClass() {
        a = b = 0;
    }
    void setData(int c, int d) {
        a = c;
        b = d;
    }
    void show() {
        cout << "a = " << a << "; b = " << b << endl;
    }
};

int main() {
    MyClass objectA, objectB;   // Створення об'єктів класу
    objectA.setData(10, 20);
    objectB.setData(0, 0);
    cout << "Об'єкт objectA до присвоєння:" << endl;
    objectA.show();
    cout << "Об'єкт objectB до присвоєння:" << endl;
    objectB.show();
    cout << endl;
    objectB = objectA;          // Присвоюємо об'єкт objectA об'єкту objectB
    cout << "Об'єкт objectA пiсля виконання операцiї присвоєння:" << endl;
    objectA.show();
    cout << "Об'єкт objectB пiсля виконання операцiї присвоєння:" << endl;
    objectB.show();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

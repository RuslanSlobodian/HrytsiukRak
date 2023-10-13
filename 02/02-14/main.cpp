// Код програми 2.14. Демонстрація механізму використання вказівника на об'єкт

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
    int number;
public:
    void setNumber(int n) {
        number = n;
    }

    void showNumber() {
        cout << "number = " << number << endl;
    }
};

int main() {
    MyClass object;             // Створення об'єкта класу
    MyClass *ptr;               // Створення вказівника на об'єкт класу MyClass

    object.setNumber(1);        // Отримуємо прямий доступ до об'єкта object
    object.showNumber();

    ptr = &object;              // Присвоюємо вказівнику ptr адресу об'єкта object
    ptr->showNumber();          // Отримуємо доступ до об'єкта object за допомогою вказівника

    //system("PAUSE");
    return EXIT_SUCCESS;
}

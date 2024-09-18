// Код програми 2.15. Демонстрація механізму інкрементування та декрементування вказівника на об'єкт

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
    MyClass objects[2];         //Оголошення масиву з 2 об'єктів
    MyClass* ptr;               //Оголошення вказівника на об'єкт класу MyClass

    objects[0].setNumber(10);   // Прямий доступ до об'єктів
    objects[1].setNumber(20);

    ptr = &objects[0];          // Отримуємо вказівник на перший елемент
    ptr->showNumber();          // Відображаємо значення елемента objects[0] за допомогою вказівника

    ptr++;                      // Переходимо до наступного об'єкта
    ptr->showNumber();          // Відображаємо значення елемента objects[1] за допомогою вказівника

    ptr--;                      // Повертаємося до попереднього об'єкта
    ptr->showNumber();          // Знову відображаємо значення елемента object[0]

    //system("PAUSE");
    return EXIT_SUCCESS;
}

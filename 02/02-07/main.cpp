// Код програми 2.7. Демонстрація механізму використання класу замість структури

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
    int c;                      // Закритий член за замовчуванням
public:
    int getC();
    void setC(int d);
};

int MyClass::getC() {
    return c;
}

void MyClass::setC(int d) {
    c = d;
}

int main() {
    MyClass object;             // Створення об'єкта класу
    object.setC(10);
    cout << "c = " << object.getC() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Код програми 2.9. Демонстрація механізму використання вбудованих методів

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
private:
    int c;                      // Закритий член за замовчуванням
public:
    void setC(int d);
    int getC();
};

inline int MyClass::getC() {
    return c;
}

inline void MyClass::setC(int d) {
    c = d;
}

int main() {
    MyClass object;             // Створення об'єкта класу
    object.setC(10);
    cout << "c = " << object.getC() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

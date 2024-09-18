// Код програми 2.4. Демонстрація механізму передачі конструктору двох параметрів

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
private:
    int c;
    int d;
public:
    MyClass(int a, int b);      // Оголошення параметризованого конструктора
    void show();
};

// Передаємо два аргументи конструктору MyClass()
MyClass::MyClass(int a, int b) {
    c = a;
    d = b;
    cout << "Об'єкт iнiцiалiзовано" << endl;
}

void MyClass::show() {
    cout << "c = " << c << "; d = " << d << endl;
}

int main() {
    system("chcp 65001");
    // Створення та ініціалізація двох об'єктів за допомогою параметризованого конструктора
    MyClass objectX(10, 20);
    MyClass objectY(0, 0);

    objectX.show();
    objectY.show();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

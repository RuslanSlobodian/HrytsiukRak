// Код програми 11.17. Демонстрація механізму використання вказівників на члени класу (початкова версія)

#include <iostream>
#include <cstdlib>

using namespace std;

class MyClass {
public:
    int number;

    void sum(int x);
};

void MyClass::sum(int x) {
    number = 0;
    for (int i = x; i; i--) number += i;
}

int main() {
    system("chcp 65001");
    int MyClass::*intPtr;       // Вказівник на атрибут класу MyClass
    void (MyClass::*fp)(int x); // Вказівник на метод класу MyClass

    MyClass object;

    intPtr = &MyClass::number;  // Отримуємо адресу атрибуту класу
    fp = &MyClass::sum;         // Отримуємо адресу метода класу

    (object.*fp)(7);            // Обчислюємо суму чисел від 1 до 7
    cout << "Сума чисел від 1 до 7 дорівнює " << object.*intPtr;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

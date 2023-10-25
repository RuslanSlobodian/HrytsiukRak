// Код програми 11.18. Демонстрація механізму використання вказівників на члени класу (модифікована версія)

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
    MyClass* objectPtr;         // objectPtr - вказівник на об'єкт класу MyClass
    MyClass object;

    objectPtr = &object;        // Присвоюємо вказівнику objectPtr адресу об'єкта
    intPtr = &MyClass::number;  // Отримуємо адресу члена даних number
    fp = &MyClass::sum;         // Отримуємо адресу функції sum()
    (objectPtr->*fp)(7);        // Тепер використовуємо оператор "->*" для виклику функції sum()
    cout << "Сума чисел від 1 до 7 дорівнює " << objectPtr->*intPtr;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

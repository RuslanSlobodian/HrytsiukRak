// Код програми 2.1. Демонстрація механізму оголошення класу та його застосування

#include <iostream>             // Для потокового введення-виведення
#include <math.h>               // Для використання математичних функцій
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
private:
    double a;
public:
    void init();                    // Ініціалізація даних класу
    void inputData(double, double); // Введення в об'єкт значення
    double outputData();            // Виведення з об'єкта значення
};

// Ініціалізація даних класу MyClass
void MyClass::init() {
    a = 0;
}

// Введення в об'єкт значення
void MyClass::inputData(double x, double y) {
    double a1 = pow(x, 1.3);
    double a2 = pow(fabs(3.2 * x - y), 0.4);
    double a3 = pow(pow(cos(a2), 2), 1.0 / 3);
    a = a1 + a3;
}

// Виведення з об'єкта значення
double MyClass::outputData() {
    return a;
}

int main() {
    // Створення двох об'єктів класу MyClass
    MyClass objectA;
    MyClass objectB;

    double x = 2.6;
    double y = 7.1;

    objectA.init();
    objectB.init();

    objectA.inputData(x, y);
    objectB.inputData(x + y, y / x);

    cout << "Вмiст об'єкта objectA: " << objectA.outputData() << endl;
    cout << "Вмiст об'єкта objectB: " << objectB.outputData() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

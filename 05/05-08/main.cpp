// Код програми 5.8. Демонстрація механізму успадкування декількох базових класів

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class BaseA {                   // Оголошення базового класу
protected:
    int x;
public:
    void showX() { cout << x << endl; }
};

class BaseB {                   // Оголошення базового класу
protected:
    int y;
public:
    void showY() { cout << y << endl; }
};

// Оголошення похідного класу Derived, успадкування двох базових класів
class Derived : public BaseA, public BaseB {
public:
    void setXY(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

int main() {
    Derived object;             // Створення об'єкта похідного класу Derived
    object.setXY(10, 20);       // Член класу Derived
    object.showX();             // Метод з класу BaseA
    object.showY();             // Метод з класу BaseB

    //system("PAUSE");
    return EXIT_SUCCESS;
}

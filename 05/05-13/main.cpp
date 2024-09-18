// Код програми 5.13. Демонстрація механізму передачі параметрів конструкторам декількох базових класів

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class BaseA {                   // Оголошення базового класу
protected:
    int c;
public:
    BaseA(int c) {
        this->c = c;
        cout << "Створення об'єкта класу BaseA" << endl;
    }

    ~BaseA() { cout << "Руйнування об'єкта класу BaseA" << endl; }
};

class BaseB {                   // Оголошення базового класу
protected:
    int f;
public:
    BaseB(int f) {
        this->f = f;
        cout << "Створення об'єкта класу BaseB" << endl;
    }

    ~BaseB() { cout << "Руйнування об'єкта класу BaseB" << endl; }
};

// Оголошення похідного класу
class Derived : public BaseA, public BaseB {
    int d;
public:
    Derived(int d, int c, int f) : BaseA(c), BaseB(f) {
        this->d = d;
        cout << "Створення об'єкта класу Derived" << endl;
    }

    ~Derived() { cout << "Руйнування об'єкта класу Derived" << endl; }

    void show() { cout << "c = " << c << "; d = " << d << "; f = " << f << endl; }
};

int main() {
    system("chcp 65001");
    Derived object(3, 4, 5);
    object.show();              // Відображає числа c = 4; d = 3; f = 5

    //system("PAUSE");
    return EXIT_SUCCESS;
}

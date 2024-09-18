// Код програми 5.14. Демонстрація механізму передачі аргументів конструкторам базового класу через конструктори похідного класу

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

    ~BaseA() { cout << "Руйнування об'єкта класу baseA" << endl; }
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
public:
    /* Конструктор класу Derived не використовує параметрів, але повинен
        оголосити їх, щоб передати конструкторам базових класів. */

    Derived(int c, int f) : BaseA(c), BaseB(f) {
        cout << "Створення об'єкта класу Derived" << endl;
    }

    ~Derived() { cout << "Руйнування об'єкта класу Derived" << endl; }

    void show() { cout << "c = " << c << "; f = " << f << endl; }
};

int main() {
    system("chcp 65001");
    Derived object(3, 4);
    object.show();              // Відображає числа c = 3; f = 4

    //system("PAUSE");
    return EXIT_SUCCESS;
}

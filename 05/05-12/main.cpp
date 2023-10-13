// Код програми 5.12. Демонстраціямеханізму передачі параметрів конструкторам базового класу

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class BaseClass {               // Оголошення базового класу
protected:
    int c;
public:
    BaseClass(int c) {
        this->c = c;
        cout << "Створення об'єкта класу BaseClass" << endl;
    }
    ~BaseClass() { cout << "Руйнування об'єкта класу BaseClass" << endl; }
};

// Оголошення похідного класу
class Derived : public BaseClass {
    int d;
public:
    // Клас Derived використовує параметр d, a параметр c
    // передається конструктору класу BaseClass.
    Derived(int d, int c) : BaseClass(c) {
        this->d = d;
        cout << "Створення об'єкта класу Derived" << endl;
    }

    ~Derived() { cout << "Руйнування об'єкта класу Derived" << endl; }

    void show() { cout << "c = " << c << "; d = " << d << endl; }
};

int main() {
    system("chcp 65001");
    Derived derived(3, 4);
    derived.show(); // Відображає числа 4 3

    //system("PAUSE");
    return EXIT_SUCCESS;
}

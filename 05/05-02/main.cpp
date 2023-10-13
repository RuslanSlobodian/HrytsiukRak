// Код програми 5.2. Демонстрація механізму доступу до членів базового класу при успадкуванні з специфікатором public

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бiблiотека С++

using namespace std;            // Використання стандартного простору iмен

class BaseClass {               // Оголошення базового класу
    int c;
    int d;
public:
    void setBase(int c, int d) {
        this->c = c;
        this->d = d;
    }

    void showBase(string str) {
        cout << str << "c = " << c << "; d = " << d << endl;
    }
};

class Derived : public BaseClass {
    int f;
public:
    Derived(int f) {
        this->f = f;
    }

    void showDerived(string strB, string strD) {
        showBase(strB);
        cout << strD << "f = " << f << endl;
    }
};

int main() {
    system("chcp 65001");
    Derived object(3);

    // Доступ до членiв класу BaseClass
    object.setBase(1, 2);
    // Доступ до членiв класу BaseClass
    object.showBase("Базовий клас: ");
    cout << endl;

    // Доступ до члена класу Derived
    object.showDerived("Базовий клас: ", "Похiдний клас: ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

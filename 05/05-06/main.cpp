// Код програми 5.6. Демонстрація некоректного використання закритих членів

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class BaseClass {               // Оголошення базового класу
protected:
    int c;
    int d;
public:
    void setBase(int c, int d) {
        this->c = c;
        this->d = d;
    }

    void showBase(string str) { cout << str << "c = " << c << "; d = " << d << endl; }
};

// Елементи класу BaseClass будуть закриті В межах класу DerivedA
class DerivedA : private BaseClass {
    int f;
public:
    // Виклики цихфункцій цілком законні, оскільки змінні c та d
    // є одночасно private-членами класу derivedA.
    void setF() { f = c * d; } // OK
    void showDerivedA(string strB, string strD) {
        showBase(strB);
        cout << strD << "f = " << f << endl;
    }
};

// Доступ до членів c, d, setBase() і showBase() не успадковується
class DerivedB : public DerivedA {
    int h;
public:
    // Неправильно, оскільки атрибути c та d закриті у межах класу DerivedA
    void setH() { h = c + d; } // Помилка
    void showDerivedB(string strB, string strD1, string strD2) {
        showDerivedA(strB, strD1);
        cout << strD2 << "h = " << h << endl;
    }
};

int main() {
    system("chcp 65001");
    DerivedA objectA; // Створення об'єкта класу DerivedA
    DerivedB objectB; // Створення об'єкта класу DerivedB
    // Помилка: не можна викликати метод setBase()
    objectA.setBase(1, 2);
    // Помилка: не можна викликати метод showBase()
    objectA.showBase("Базовий клас: ");
    cout << endl;

    // Помилка: не можна викликати метод setBase()
    objectB.setBase(3, 4);
    // Помилка: не можна викликатифункцію showBase()
    objectB.showBase("Базовий клас: ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

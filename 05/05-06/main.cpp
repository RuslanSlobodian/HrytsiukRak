// Код програми 5.6. Демонстрація некоректного використання закритих членів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class BaseClass{		 // Оголошення базового класу
protected:
    int c, d;
public:
    void setB(int a, int b) { c = a; d = b; }
    void showB(char *s) { cout << s << "c= " << c << "; d= " << d << endl; }
};
// Елементи класу baseClass будуть закриті умежах класу derivedA.
class derivedA : private BaseClass {
    int f;
public:
    // Виклики цихфункцій цілком законні, оскільки змінні c та d
    // є одночасно private-членами класу derivedA.
    void setF() { f = c*d; } // OK
    void showF(char *b, char *p)
    { showB(b); cout << p << "f= " << f << endl; }
};

// Доступ до членів c, d, setB() і showB() не успадковується.
class derivedB : public derivedA {
    int h;
public:
    // Неправильно, оскільки члени-даних c та d закриті у межах класу derivedA.
    void setM() { h = c + d; } // Помилка
    void showM(char *b, char *p1, char *p2)
    { showF(b, p1); cout << p2 << "h= " << h << endl; }
};

int main()
{
    derivedA ObjA; // Створення об'єкта класу
    derivedB ObjB; // Створення об'єкта класу
    // Помилка: не можна викликатифункцію setB()
    ObjA.setB(1, 2);
    // Помилка: не можна викликатифункцію showB()
    ObjA.showB("Базовий клас: "); cout << endl;

    // Помилка: не можна викликатифункцію setB()
    ObjB.setB(3, 4);
    // Помилка: не можна викликатифункцію showB()
    ObjB.showB("Базовий клас: ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

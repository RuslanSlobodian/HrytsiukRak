// Код програми 11.14. Демонстрація механізму ініціалізації атрибутів з використанням конструкторів класу

#include <iostream>
#include <cstdlib>

using namespace std;

class MyClass {
    int a;
    int b;
public:
    // Ініціалізація a і b у конструкторі MyClass(), використовуючи звичайний синтаксис
    MyClass(int a, int b) {
        this->a = a;
        this->b = b;
    }

    int getA() const { return a; }
    int getB() const { return b; }
};

int main() {
    system("chcp 65001");
    MyClass objectA(7, 9), objectB(5, 2);
    cout << "Значення об'єкта objectA = " << objectA.getA() << " i " << objectA.getB() << endl;
    cout << "Значення об'єкта objectB = " << objectB.getA() << " i " << objectB.getB() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

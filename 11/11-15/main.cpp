// Код програми 11.15. Демонстрація механізму оголошення атрибутів класу з використанням модифікатора const

#include <iostream>
#include <cstdlib>

using namespace std;

class MyClass {
    const int a;                // константний атрибут класу
    const int b;                // константний атрибут класу
public:
    // Ініціалізація членів a і b з використанням альтернативного синтаксису ініціалізації
    MyClass(int a, int b) : a(a), b(b) {}

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

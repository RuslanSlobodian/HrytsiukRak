// Код програми 7.11. Демонстрація безпосередньо заданої спеціалізації класів

#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
class MyClass {                 // Оголошення класового типу
    T x;
public:
    MyClass(T x) {
        cout << "У тiлi узагальненого класу MyClass" << endl;
        this->x = x;
    }

    T getX() const { return x; }
};

// Безпосередня спеціалізація для типу int
template<>
class MyClass<int> {
    int x;
public:
    MyClass(int x) {
        cout << "У тiлi спецiалiзацiї MyClass<int>" << endl;
        this->x = x * x;
    }

    int getX() const { return x; }
};

int main() {
    system("chcp 65001");
    MyClass<double> objectA(10.1);
    cout << "double: " << objectA.getX() << endl << endl;
    MyClass<int> objectB(5);
    cout << "int: " << objectB.getX() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

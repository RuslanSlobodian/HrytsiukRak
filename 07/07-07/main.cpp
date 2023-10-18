// Код програми 7.7. Демонстрація механізму створення класу з двома узагальненими типами даних

#include <iostream>
#include <cstdlib>

using namespace std;

template<typename aType, class bType>
class MyClass {
    aType c;
    bType d;
public:
    MyClass(aType objectA, bType objectB) {
        c = objectA;
        d = objectB;
    }

    void showType() { cout << "c = " << c << "; d = " << d << endl; }
};

int main() {
    system("chcp 65001");
    MyClass<int, double> objectA(10, 0.23);
    MyClass<char, char*> objectB('x', "Це тест");
    objectA.showType();         // Відображення int- і double-значень
    objectB.showType();         // Відображення значень типу char і char*

    //system("PAUSE");
    return EXIT_SUCCESS;
}

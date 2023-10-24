// Код програми 10.5. Демонстрація механізму застосування оператора typeid до шаблонних класів

#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
class MyClass {
    T a;
public:
    MyClass(T a) { this->a = a; }
    //. . .
};

int main() {
    system("chcp 65001");
    MyClass<int> objectA(10);
    MyClass<int> objectB(9);
    MyClass<double> objectC(7.2);

    cout << "Об'єкт objectA має тип ";
    cout << typeid(objectA).name() << endl;

    cout << "Об'єкт objectB має тип ";
    cout << typeid(objectB).name() << endl;

    cout << "Об'єкт objectC має тип ";
    cout << typeid(objectC).name() << endl;

    cout << endl;

    if (typeid(objectA) == typeid(objectB))
        cout << "Об'єкти objectA i objectB мають однаковий тип" << endl;
    if (typeid(objectA) == typeid(objectC))
        cout << "Помилка" << endl;
    else
        cout << "Об'єкти objectA i objectC мають рiзнi типи" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

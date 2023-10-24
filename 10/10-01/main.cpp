// Код програми 10.1. Демонстрація механізму використання оператора typeid

#include <iostream>
#include <cstdlib>

using namespace std;

class MyClass {
    //. . .
};

int main() {
    system("chcp 65001");
    int c;
    int d;
    float f;
    MyClass obj;
    cout << "Тип змiнної c: " << typeid(c).name() << endl;
    cout << "Тип змiнної f: " << typeid(f).name() << endl;
    cout << "Тип змiнної obj: " << typeid(obj).name() << endl << endl;

    if (typeid(c) == typeid(d))
        cout << "Типи змiнних c та d однаковi" << endl;
    if (typeid(c) != typeid(f))
        cout << "Типи змiнних c та f неоднаковi" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

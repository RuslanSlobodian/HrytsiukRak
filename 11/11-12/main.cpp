// Код програми 11.12. Демонстрація механізму використання специфікатора explicit

#include <iostream>
#include <cstdlib>

using namespace std;

class MyClass {
    int a;
public:
    explicit MyClass(int a) { this->a = a; }
    int getData() const { return a; }
};

int main() {
    MyClass object(4);
//    object = 10;              // explicit забороняє так робити
    cout << object.getData();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

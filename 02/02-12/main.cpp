// Код програми 2.12. Демонстрація механізму ініціалізації масиву об'єктів

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
    int a;
public:
    MyClass(int b) {
        a = b;
    }
    double getData() {
        return a;
    }
};

int main() {
    MyClass array[4] = { MyClass(1), MyClass(2), MyClass(3), MyClass(4) };
    for(int i = 0; i < 4; i++)
        cout << "array[" << i << "] = " << array[i].getData() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Код програми 2.6. Демонстрація механізму використання структури для створення класу

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

struct MyStruct {               // Оголошення структурного типу
    int getC();                  // Ці члени відкриті (public)
    void setC(int d);            // за замовчуванням
private:
    int c;
};

int MyStruct::getC() {
    return c;
}

void MyStruct::setC(int d) {
    c = d;
}

int main() {
    MyStruct object;            // Створення об'єкта структури
    object.setC(10);
    cout << "c = " << object.getC() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

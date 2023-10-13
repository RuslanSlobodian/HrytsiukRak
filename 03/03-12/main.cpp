// Код програми 3.12. Демонстрація механізму появи помилки, яка виникає при поверненні об'єкта функцією

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++
#include <string.h>

using namespace std;            // Використання стандартного простору імен

class MyClass {                // Оголошення класового типу
    char *s;
public:
    MyClass() {
        s = nullptr;
    }

    ~MyClass() {
        if (s) {
            delete[] s;
            cout << "Звiльнення s-пам'ятi" << endl;
        }
    }

    void set(char *str) {       // Завантаження рядка
        s = new char[strlen(str) + 1];
        strcpy(s, str);
    }

    void show() {
        cout << "s = " << s << endl;
    }
};

// Ця функція повертає об'єкт типу strClass
MyClass init() {
    MyClass objectB;
    char str[80];
    cout << "Введiть рядок: ";
    cin >> str;
    objectB.set(str);
    return objectB;
}

int main() {
    system("chcp 65001");
    MyClass objectA;           // Створення об'єкта класу
    // Присвоюємо об'єкт, повернутий функцією init(), об'єкту objectA
    objectA = init();           // Цей рядок коду генерує помилку!!!!
    objectA.show();             // Відображення "сміття"

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Код програми 4.7. Демонстрація механізму появи помилки, яка виникає при поверненні об'єкта з функції

#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

class StrClass {                // Оголошення класового типу
    char *charPtr;
public:
    StrClass() { charPtr = nullptr; }

    StrClass(const StrClass &object); // Оголошення конструктора копії
    ~StrClass() {
        if (charPtr) {
            delete[] charPtr;
            cout << "Звiльнення charPtr-пам'ятi" << endl;
        }
    }

    void show(const char *c) { cout << c << charPtr << endl; }

    void set(const char *str);
};

// Визначення конструктора копії
StrClass::StrClass(const StrClass &object) {
    charPtr = new char[strlen(object.charPtr) + 1];
    strncpy(charPtr, object.charPtr, sizeof(object.charPtr) + 1);
}

// Завантаження рядка
void StrClass::set(const char *str) {
    charPtr = new char[strlen(str) + 1];
    strncpy(charPtr, str, sizeof(str) + 1);
}

// Ця функція повертає об'єкт типу StrClass
StrClass init() {
    char str[80];
    StrClass object;
    cout << "Введiть рядок: ";
    cin >> str;
    object.set(str);
    return object;
}

int main() {
    system("chcp 65001");
    StrClass object; // Створення об'єкта класу StrClass
    // Присвоюємо об'єкт, повернутий функцією init(), об'єкту object
    object = init(); // Цей рядок коду генерує помилку!!!!
    object.show("charPtr = ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

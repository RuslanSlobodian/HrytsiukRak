// Код програми 4.8. Демонстрація механізму появи помилки, яка може виникнути при поверненні об'єкта з функції

#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

class StrClass {                // Оголошення класового типу
    char *charPtr;
public:
    StrClass();                 // Оголошення звичайного конструктора
    StrClass(const StrClass &object); // Оголошення конструктора копії
    ~StrClass() {               // Оголошення деструктора
        if (charPtr) {
            delete[]charPtr;
            cout << "Звiльнення charPtr-пам'ятi" << endl;
        }
    }

    void show(string str) { cout << str << charPtr << endl; }

    void set(const char *str);

    // Перевизначений оператор присвоєння
    StrClass operator=(const StrClass &object);
};

// Визначення звичайного конструктора
StrClass::StrClass() {
    charPtr = nullptr;        // Член charPtr вказує на NULL-рядок
}

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

// Перевизначення оператора присвоєння "="
StrClass StrClass::operator=(const StrClass &object) {
    // Якщо виділена область пам'яті має недостатній розмір, виділяється нова область пам'яті
    if (strlen(object.charPtr) > strlen(charPtr)) {
        delete[]charPtr;
        charPtr = new char[strlen(object.charPtr) + 1];
    }
    strncpy(charPtr, object.charPtr, sizeof(object.charPtr) + 1);

    // Повернення модифікованого об'єкта операнда, адресованого вказівником
    return *this;
}

// Ця функція повертає об'єкт типу StrClass
StrClass init() {
    StrClass object;
    char str[80];
    cout << "Введiть рядок: ";
    cin >> str;
    object.set(str);
    return object;
}

int main() {
    system("chcp 65001");
    StrClass object;            // Створення об'єкта класу

    // Присвоюємо об'єкт, повернутий функцією init(), об'єкту object
    object = init();            // Тепер тут все гаразд!
    object.show("charPtr = ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

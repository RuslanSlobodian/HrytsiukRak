// Код програми 4.8. Демонстрація механізму появи помилки, яка може виникнути при поверненні об'єкта з функції

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <string.h>
using namespace std; 			// Використання стандартного простору імен

class StrClass {                // Оголошення класового типу
    char *s;
public:
    StrClass();                 // Оголошення звичайного конструктора
    StrClass(const StrClass &object); // Оголошення конструктора копії
    ~StrClass() {
        if(s) {
            delete[]s;
            cout << "Звiльнення s-пам'ятi" << endl;
        }
    }
    void show(char *c) { cout << c << s << endl; }
    void set(char *str);
    // Перевизначений оператор присвоєння
    StrClass operator=(const StrClass &object);
};

// Визначення звичайного конструктора
StrClass::StrClass() {
    s = new char ('\0');        // Член s вказує на NULL-рядок
}

// Визначення конструктора копії
StrClass::StrClass(const StrClass &object) {
    s = new char[strlen(object.s)+1];
    strcpy(s, object.s);
}

// Завантаження рядка
void StrClass::set(char *str) {
    s = new char[strlen(str)+1];
    strcpy(s, str);
}

// Перевизначення оператора присвоєння "="
StrClass StrClass::operator=(const StrClass &object) {
    // Якщо виділена область пам'яті має недостатній розмір, виділяється нова область пам'яті
    if(strlen(object.s) > strlen(s)) {
        delete[]s;
        s = new char[strlen(object.s)+1];
    }
    strcpy(s, object.s);

    // Повернення модифікованого об'єкта операнда, адресованого вказівником
    return *this;
}

// Ця функція повертає об'єкт типу strClass
StrClass init() {
    StrClass object;
    char str[80];
    cout << "Введiть рядок: ";
    cin >> str;
    object.set(str);
    return object;
}

int main() {
    StrClass object;            // Створення об'єкта класу

    // Присвоюємо об'єкт, повернутий функцією init(), об'єкту object
    object = init();            // Тепер тут все гаразд!
    object.show("s = ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Код програми 4.7. Демонстрація механізму появи помилки, яка виникає при поверненні об'єкта з функції

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <string.h>
using namespace std; 			// Використання стандартного простору імен

class StrClass {                // Оголошення класового типу
    char *s;
public:
    StrClass() { s = 0; }
    StrClass(const StrClass &object); // Оголошення конструктора копії
    ~StrClass() {
        if(s) {
            delete[] s;
            cout << "Звiльнення s-пам'ятi" << endl;
        }
    }
    void show(char *c) { cout << c << s << endl; }
    void set(char *str);
};

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

// Ця функція повертає об'єкт типу strClass
StrClass init() {
    char str[80];
    StrClass object;
    cout << "Введiть рядок: ";
    cin >> str;
    object.set(str);
    return object;
}

int main() {
    StrClass object; // Створення об'єкта класу
    // Присвоюємо об'єкт, повернутий функцією init(), об'єкту object
    object = init(); // Цей рядок коду генерує помилку!!!!
    object.show("s = ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

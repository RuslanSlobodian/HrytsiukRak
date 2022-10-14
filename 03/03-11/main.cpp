// Код програми 3.11. Демонстрація механізму повернення об'єкта функцією

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <string.h>

using namespace std; 			// Використання стандартного простору імен

class StrClass {                // Оголошення класового типу
    char str[80];
public:
    void set(char* s) {
        strcpy(str, s);
    }
    void show() { cout << "Рядок: " << str << endl; }
};

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
    object = init();            // Присвоюємо об'єкт, повернутий функцією init(), об'єкту obj
    object.show();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

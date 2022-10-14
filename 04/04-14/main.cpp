/*
 * Код програми 4.14. Демонстрація механізму конкатенації та присвоєння класу
 * рядків з рядками, що закінчуються нульовим символом
 */

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <string.h>

using namespace std; 			// Використання стандартного простору імен

class StrClass {                // Оголошення класового типу
    char string[80];
public:
    StrClass(char *str = "") {
        strcpy(string, str);
    }

    // Конкатенація об'єктів типу strClass
    StrClass operator+(StrClass object);

    // Конкатенація об'єкта з рядком, що завершується нулем
    StrClass operator+(char *str);

    // Присвоєння одного об'єкта типу strClass іншому
    StrClass operator=(StrClass object);

    // Присвоєння рядка об'єкту типу strClass, що завершується нулем
    StrClass operator=(char *str);

    void show(char *s) { cout << s << string << endl; }
};

StrClass StrClass::operator+(StrClass object) {
    StrClass tmp; // Створення тимчасового об'єкта
    strcpy(tmp.string, string);
    strcat(tmp.string, object.string);
    return tmp; // Повертає модифікований тимчасовий об'єкт
}

StrClass StrClass::operator=(StrClass object) {
    strcpy(string, object.string);
    // Повернення модифікованого об'єкта операнда, адресованого покажчиком
    return *this;
}

StrClass StrClass::operator=(char *str) {
    StrClass tmp;               // Створення тимчасового об'єкта
    strcpy(string, str);
    strcpy(tmp.string, string);
    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}
StrClass StrClass::operator+(char *str) {
    StrClass tmp;               // Створення тимчасового об'єкта
    strcpy(tmp.string, string);
    strcat(tmp.string, str);
    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

int main() {
    StrClass objectA("Привiт ");
    StrClass objectB("всiм");
    StrClass objectC;

    objectA.show("A: ");
    objectB.show("B: ");
    objectC = objectA + objectB;
    objectC.show("C= A + B: ");
    objectA = "для програмування, тому що";
    objectA.show("A: ");
    objectB = objectC = "C++ це супер";
    objectC = objectC + " " + objectA + " " + objectB;
    objectC.show("C: ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

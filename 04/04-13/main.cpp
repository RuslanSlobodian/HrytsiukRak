// Код програми 4.13. Демонстрація механізму конкатенації та присвоєння класу рядків

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <string.h>

using namespace std; 			// Використання стандартного простору імен

class StrClass {                // Оголошення класового типу
    char string[80];
public:
    StrClass(char *str ="") {
        strcpy(string, str);
    }
    StrClass operator+(StrClass object); // Конкатенація рядків
    StrClass operator=(StrClass object); // Присвоєння рядків

    void show(char *s) {        // Виведення рядка
        cout << s << string << endl;
    }
};

// Конкатенація двох рядків
StrClass StrClass::operator+(StrClass object) {
    StrClass tmp;               // Створення тимчасового об'єкта
    strcpy(tmp.string, string);
    strcat(tmp.string, object.string);
    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

// Присвоєння одного рядка іншому
StrClass StrClass::operator=(StrClass object) {
    strcpy(string, object.string);
    // Повернення модифікованого об'єкта операнда, адресованого покажчиком
    return *this;
}

int main () {
    StrClass objectA("Всiм ");
    StrClass objectB("привiт");
    StrClass objectC;

    objectA.show("A: ");
    objectB.show("B: ");

    objectC = objectA + objectB;
    objectC.show("C = A + B : ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

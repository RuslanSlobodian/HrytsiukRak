// Код програми 4.13. Демонстрація механізму конкатенації та присвоєння класу рядків

#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;            // Використання стандартного простору імен

class StrClass {                // Оголошення класового типу
    char charArray[80];
public:
    StrClass(const char* str = "") {
        strcpy(charArray, str);
    }

    StrClass operator+(StrClass object); // Конкатенація рядків
    StrClass operator=(StrClass object); // Присвоєння рядків

    void show(string str) {     // Виведення рядка
        cout << str << charArray << endl;
    }
};

// Конкатенація двох рядків
StrClass StrClass::operator+(StrClass object) {
    StrClass tmp;               // Створення тимчасового об'єкта
    strcpy(tmp.charArray, charArray);
    strcat(tmp.charArray, object.charArray);
    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

// Присвоєння одного рядка іншому
StrClass StrClass::operator=(StrClass object) {
    strcpy(charArray, object.charArray);
    // Повернення модифікованого об'єкта операнда, адресованого вказівником
    return *this;
}

int main() {
    system("chcp 65001");
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

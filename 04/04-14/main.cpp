// Код програми 4.14. Демонстрація механізму конкатенації та присвоєння класу
// рядків з рядками, що закінчуються нульовим символом


#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

class StrClass {                // Оголошення класового типу
    char charArray[80];
public:
    StrClass(const char* str = "") {
        strcpy(charArray, str);
    }

    StrClass(const StrClass& source) {
        strcpy(charArray, source.charArray);
    }


    // Конкатенація об'єктів типу StrClass
    StrClass operator+(StrClass object);

    // Конкатенація об'єкта з рядком, що завершується нулем
    StrClass operator+(const char* str);

    // Присвоєння одного об'єкта типу StrClass іншому
    StrClass& operator=(StrClass object);

    // Присвоєння рядка об'єкту типу StrClass, що завершується нулем
    StrClass& operator=(const char* str);

    void show(string str) { cout << str << charArray << endl; }
};

StrClass StrClass::operator+(StrClass object) {
    StrClass tmp; // Створення тимчасового об'єкта
    strcpy(tmp.charArray, charArray);
    strcat(tmp.charArray, object.charArray);
    return tmp; // Повертає модифікований тимчасовий об'єкт
}

StrClass& StrClass::operator=(StrClass object) {
    strcpy(charArray, object.charArray);
    // Повернення модифікованого об'єкта операнда, адресованого вказівником this
    return *this;
}

StrClass& StrClass::operator=(const char* str) {
    strcpy(charArray, str);
    return *this;
}

StrClass StrClass::operator+(const char* str) {
    StrClass tmp;               // Створення тимчасового об'єкта
    strcpy(tmp.charArray, charArray);
    strcat(tmp.charArray, str);
    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

int main() {
    system("chcp 65001");
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
    objectC.show("C: ");
    objectC = objectC + " " + objectA + " " + objectB;
    objectC.show("C: ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

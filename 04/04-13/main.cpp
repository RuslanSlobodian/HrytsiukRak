//Код програми 4.13. Демонстрація механізму конкатенації та присвоєння класу рядків

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <string.h>

using namespace std; 			// Використання стандартного простору імен

class strClass { // Оголошення класового типу
    char string[80];
public:
    strClass(char *str ="") { strcpy(string, str); }
    strClass operator+(strClass obj); // Конкатенація рядків
    strClass operator=(strClass obj); // Присвоєння рядків
    // Виведення рядка
    void Show(char *s) { cout << s << string << endl; }
};

// Конкатенація двох рядків
strClass strClass::operator+(strClass obj)
{
    strClass tmp; // Створення тимчасового об'єкта
    strcpy(tmp.string, string);
    strcat(tmp.string, obj.string);
    return tmp; // Повертає модифікований тимчасовий об'єкт
}
// Присвоєння одного рядка іншому
strClass strClass::operator=(strClass obj)
{
    strcpy(string, obj.string);
    // Повернення модифікованого об'єкта операнда, адресованого покажчиком
    return *this;
}


int main () {
    strClass ObjA("Всiм "), ObjB("привiт"), ObjC;
    ObjA.Show("A: ");
    ObjB.Show("B: ");
    ObjC = ObjA + ObjB;
    ObjC.Show("C=A+B: ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

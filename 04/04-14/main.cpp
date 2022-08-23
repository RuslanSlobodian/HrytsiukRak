//Код програми 4.14. Демонстрація механізму конкатенації та присвоєння класу
//рядків з рядками, що закінчуються нульовим символом

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <string.h>

using namespace std; 			// Використання стандартного простору імен

class strClass { // Оголошення класового типу
    char string[80];
public:
    strClass(char *str = "") { strcpy(string, str); }
    // Конкатенація об'єктів типу strClass
    strClass operator+(strClass obj);
    // Конкатенація об'єкта з рядком, що завершується нулем
    strClass operator+(char *str);
    // Присвоєння одного об'єкта типу strClass іншому
    strClass operator=(strClass obj);
    // Присвоєння рядка об'єкту типу strClass, що завершується нулем
    strClass operator=(char *str);
    void Show(char *s) { cout << s << string << endl; }
};
strClass strClass::operator+(strClass obj)
{
    strClass tmp; // Створення тимчасового об'єкта
    strcpy(tmp.string, string);
    strcat(tmp.string, obj.string);
    return tmp; // Повертає модифікований тимчасовий об'єкт
}
strClass strClass::operator=(strClass obj)
{
    strcpy(string, obj.string);
    // Повернення модифікованого об'єкта операнда, адресованого покажчиком
    return *this;
}
strClass strClass::operator=(char *str)
{
    strClass tmp; // Створення тимчасового об'єкта
    strcpy(string, str);
    strcpy(tmp.string, string);
    return tmp; // Повертає модифікований тимчасовий об'єкт
}
strClass strClass::operator+(char *str)
{
    strClass tmp; // Створення тимчасового об'єкта
    strcpy(tmp.string, string);
    strcat(tmp.string, str);
    return tmp; // Повертає модифікований тимчасовий об'єкт
}

int main()
{
    strClass ObjA("Привiт "), ObjB("всiм"), ObjC;
    ObjA.Show("A: ");
    ObjB.Show("B: ");
    ObjC = ObjA + ObjB;
    ObjC.Show("C=A+B: ");
    ObjA = "для програмування, тому що";
    ObjA.Show("A: ");
    ObjB = ObjC = "C++ це супер";
    ObjC = ObjC + " " + ObjA + " " + ObjB;
    ObjC.Show("C: ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

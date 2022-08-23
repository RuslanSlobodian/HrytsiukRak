//Код програми 3.11. Демонстрація механізму повернення об'єкта функцією

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <string.h>

using namespace std; 			// Використання стандартного простору імен

class strClass { // Оголошення класового типу
    char str[80];
public:
    void Set(char *s) { strcpy(str, s); }
    void Show() { cout << "Рядок: " << str << endl; }
};
// Ця функція повертає об'єкт типу strClass.
strClass Init()
{
    strClass obj;
    char str[80];
    cout << "Введiть рядок: ";
    cin >> str;
    obj.Set(str);
    return obj;
}

int main()
{
    strClass Obj; // Створення об'єкта класу
    Obj = Init(); // Присвоюємо об'єкт, повернутий функцією Init(), об'єкту Obj
    Obj.Show();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 3.12. Демонстрація механізму появи помилки, яка виникає при поверненні об'єкта функцією

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <string.h>

using namespace std; 			// Використання стандартного простору імен

class strClass { // Оголошення класового типу
    char *s;
public:
    strClass() { s = 0; }
    ~strClass() { if(s) delete[]s; cout << "Звiльнення s-пам'ятi" << endl; }
    void Set(char *str) { s = new char[strlen(str)+1]; strcpy(s, str); } // Завантаження рядка.
    void Show() { cout << "s= " << s << endl; }
};
// Ця функція повертає об'єкт типу strClass.
strClass Init()
{
    strClass obj; char str[80];
    cout << "Введiть рядок: "; cin >> str;
    obj.Set(str);
    return obj;
}

int main()
{
    strClass Obj; // Створення об'єкта класу
    // Присвоюємо об'єкт, повернутий функцією Init(), об'єкту Obj.
    Obj = Init(); // Ця настанова генерує помилку!!!!
    Obj.Show(); // Відображення "сміття".

    //system("PAUSE");
    return EXIT_SUCCESS;
}

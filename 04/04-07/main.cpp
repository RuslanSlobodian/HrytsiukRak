//Код програми 4.7. Демонстрація механізму появи помилки, яка виникає при поверненні об'єкта з функції

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <string.h>
using namespace std; 			// Використання стандартного простору імен

class strClass { // Оголошення класового типу
    char *s;
public:
    strClass() { s = 0; }
    strClass(const strClass &obj); // Оголошення конструктора копії
    ~strClass() {if(s) delete[]s; cout << "Звiльнення s-пам'ятi" << endl; }
    void Show(char *c) { cout << c << s << endl; }
    void Set(char *str);
};
// Визначення конструктора копії.
strClass::strClass(const strClass &obj)
{
    s = new char[strlen(obj.s)+1];
    strcpy(s, obj.s);
}
// Завантаження рядка.
void strClass::Set(char *str)
{
    s = new char[strlen(str)+1];
    strcpy(s, str);
}
// Ця функція повертає об'єкт типу strClass.
strClass Init()
{
    char str[80];
    strClass obj;
    cout << "Введiть рядок: "; cin >> str;
    obj.Set(str);
    return obj;
}

int main()
{
    strClass Obj; // Створення об'єкта класу
    // Присвоюємо об'єкт, повернутий функцією Init(), об'єкту Obj.
    Obj = Init(); // Ця настанова генерує помилку!!!!
    Obj.Show("s= ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

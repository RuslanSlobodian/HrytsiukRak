//Код програми 4.8. Демонстрація механізму появи помилки, яка може виникнути при поверненні об'єкта з функції

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <string.h>
using namespace std; 			// Використання стандартного простору імен

class strClass { // Оголошення класового типу
    char *s;
public:
    strClass(); // Оголошення звичайного конструктора
    strClass(const strClass &obj); // Оголошення конструктора копії
    ~strClass() { if(s) delete[]s; cout << "Звiльнення s-пам'ятi" << endl; }
    void Show(char *c) { cout << c << s << endl; }
    void Set(char *str);
    // Перевизначений оператор присвоєння
    strClass operator=(const strClass &obj);
};
// Визначення звичайного конструктора.
strClass::strClass()
{
    s = new char ('\0'); // Член s вказує на NULL-рядок.
}
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
// Перевизначення оператора присвоєння "=".
strClass strClass::operator=(const strClass &obj)
{
    /* Якщо виділена область пам'яті має недостатній
    розмір, виділяється нова область пам'яті. */
    if(strlen(obj.s) > strlen(s)) {
        delete[]s;
        s = new char[strlen(obj.s)+1];
    }
    strcpy(s, obj.s);
    // Повернення модифікованого об'єкта операнда, адресованого покажчиком
    return *this;
}
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
    // Присвоюємо об'єкт, повернутий функцією Init(), об'єкту Obj
    Obj = Init(); // Тепер тут все гаразд!
    Obj.Show("s= ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

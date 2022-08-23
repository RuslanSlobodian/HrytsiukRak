//Код програми 7.2. Демонстрацiя механiзму перевизначення шаблонної функцiї
#include <cstring>
#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бiблiотека С++

using namespace std;

template <class aType> void swapAB(aType &a, aType &b)
{
    aType tmp;  // Створення тимчасової змiнної

    tmp = a;
    a = b;
    b = tmp;
    cout << "Виконується шаблонна функцiя swapAB" << endl;
}

// Ця функцiя перевизначає узагальнену версiю функцiї swapAB() для int-параметрiв.
void swapAB(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    cout << "Це int-спецiалiзацiя функцiї swapAB" << endl;
}

int main()
{
    int i = 10, j = 20;
    double x = 10.1, y = 23.3;
    char a = 'x', b = 'z';

    cout << "Початковi значення i, j: " << i << " " << j << endl;
    cout << "Початковi значення x, y: " << x << " " << y << endl;
    cout << "Початковi значення a, b: " << a << " " << b << endl;
    swapAB(i, j);  // Викликається безпосередньо перевизначена функцiя swapAB().
    swapAB(x, y);  // Викликається узагальнена функцiя swapAB().
    swapAB(a, b);  // Викликається узагальнена функцiя swapAB().

    cout << "Пiсля перестановки i, j: " << i << " " << j << endl;
    cout << "Пiсля перестановки x, y: " << x << " " << y << endl;
    cout << "Пiсля перестановки a, b: " << a << " " << b << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}




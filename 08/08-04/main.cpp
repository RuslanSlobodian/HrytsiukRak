//Код програми 8.4. Демонстрація механізму локалізації блоку try у рамках роботи самої функції

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

// Функціонування блоків try/catch поновлюється під час кожного входження у функцію.
void Xhandler(int test)
{
    try {
        if(test) throw test;
        }
    catch(int c) {
        cout << "Перехоплення! Виняток №: " << c << endl;
        }
}
int main()
{
    cout << "Початок" << endl;

    Xhandler(1);
    Xhandler(2);
    Xhandler(0);
    Xhandler(3);

    cout << "Кiнець програми";

    //system("PAUSE");
    return EXIT_SUCCESS;
}

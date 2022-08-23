//Код програми 8.6. Демонстрація механізму використання декількох catch-настанов

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

// Тут можливе перехоплення винятків різних типів.
void Xhandler(int test)
{
    try {
        if(test) throw test;
        else throw "Значення дорiвнює нулю.";
    }
    catch(int c) {
        cout << "Перехоплення! Виняток №: " << c << endl;
    }
    catch(const char *str) {
        cout << "Перехоплення рядка: " << str << endl;
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

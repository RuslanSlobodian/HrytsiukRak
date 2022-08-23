//Код програми 8.11. Демонстрація механізму повторного генерування винятку типу char *

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

void Xhandler() {
    try {
        throw "Привіт";                // Генерує винятки типу char *
    }
    catch(const char *) { 			// Перехоплює винятки типу char *
        cout << "Перехоплення винятку у функцiї Xhandler" << endl;
        throw;                           // Повторне генерування винятку типу char *,
        // яке перехоплюватиметься поза функцією Xhandler.
    }
}

int main()
{
    cout << "Початок" << endl;
    try {
        Xhandler();
    }
    catch(const char *) {
        cout << "Перехоплення винятку у функцiї main()" << endl;
    }
    cout << "Кiнець програми";

    //system("PAUSE");
    return EXIT_SUCCESS;
}

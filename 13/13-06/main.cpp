//Код програми 13.

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

#define TOM

int main()
{
#ifdef TOM
    cout << "Програмiст Том" << endl;
#else
    cout << "Програмiст невiдомий" << endl;
#endif
#ifndef RALPH
    cout << "Iм'я RALPH не визначене" << endl;
#endif

    //system("PAUSE");
    return EXIT_SUCCESS;
}

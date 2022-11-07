//Код програми 13.3. Демонстрація коректної роботи коду програми

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

#define EVEN(a) (a) % 2 == 0 ? 1 : 0

int main()
{
    if(EVEN(9 + 1)) {
        cout << "парне число";
    } else {
        cout << "непарне число";
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

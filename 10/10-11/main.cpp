//Код програми 10.11. Демонстрація механізму використання оператора reinterpret_cast

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

int main()
{
    int c;
    char *p = "Це короткий рядок.";

    c = reinterpret_cast<int> (p); // Приводимо покажчик до типу int.

    cout << c;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

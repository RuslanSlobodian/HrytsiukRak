//Код програми 9.8. Демонстрація механізму використання маніпулятора ws, який пропускає провідні "пропускні" символи

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

int main()
{
    char str[80];
    cin >> ws >> str;
    cout << str;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

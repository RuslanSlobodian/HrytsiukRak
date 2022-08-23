//Код програми 13.1. Демонстрація механізму використання "функціональних" акровизначень

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

#define MIN(a, b) (((a)<(b))? a: b)

int main()
{
    int x = 10, y = 20;
    cout << "Мiнiмум дорiвнює: " << MIN(x, y);

    //system("PAUSE");
    return EXIT_SUCCESS;
}

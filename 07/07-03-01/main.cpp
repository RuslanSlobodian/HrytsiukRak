//Код програми 7.3.1. Демонстрація механізму перевизначення специфікації шаблону функції


#include <cstring>
#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std;

// Перша версія шаблону Fun().
template <class aType> void Fun(aType a)
{
    cout << "Виконується функцiя Fun(aType a)" << endl;
}
// Друга версія шаблону Fun().
template <class aType, class bType> void Fun(aType a, bType b)
{
    cout << "Виконується функцiя Fun(aType a, bType b)" << endl;
}

int main()
{
    Fun(10); // Викликається функція Fun(a).
    Fun(10, 20); // Викликається функція Fun(a, b).
    //system("PAUSE");
    return EXIT_SUCCESS;
}

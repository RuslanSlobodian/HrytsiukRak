//Код програми 10.9. Демонстрація механізму використання оператора const_cast

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

void Fun(const int *p)
{
    int *v;
    v = const_cast<int *> (p); // Перевизначення const-атрибуту.
    *v = 100; // Тепер об'єкт можна модифікувати
}

int main()
{
    int x = 99;
    cout << "Значення x до виклику функцiї Fun(): " << x << endl;

    Fun(&x);
    cout << "Значення x пiсля виклику функцiї Fun(): " << x << endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}

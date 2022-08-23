//Код програми 11.4. Демонстрація механізму внесення в глобальний простірімен декількох імен

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

// Отримуємо доступ до імен потоків cout і cin
using std::cout;
using std::cin;

int main()
{
    double n;

    cout << "Введiть число: "; cin >> n;

    cout << "Ви ввели число ";
    cout << n;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 9.10. Демонстрація механізму створення маніпулятора prompt()

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <iomanip>		 // Використанняманіпуляторів введення-виведення

using namespace std; 			// Використання стандартного простору імен

istream &prompt(istream &stream)
{
    cin >> hex;
    cout << "Введiть число в шiстнадцятково муформатi: ";
    return stream; // Повертає посилання на параметр streamint main()
}

int main ()
{
    int c;
    cin >> prompt >> c;
    cout << c; // Виведення числа вшістнадцятковомуформаті

    //system("PAUSE");
    return EXIT_SUCCESS;
}

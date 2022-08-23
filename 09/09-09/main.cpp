//Код програми 9.9. Демонстрація механізму створення маніпулятора setup()

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <iomanip>		 // Використанняманіпуляторів введення-виведення

using namespace std; 			// Використання стандартного простору імен

ostream &setup(ostream&stream)
{
    stream.setf(ios::left); // Вирівнювання лівим краєм

    /* Встановлюєширину поля в 10 символів ізадає якзаповнювальний
        символ знак долара */
    stream << setw(10) << setfill('$');

    return stream; // Повертає посилання на параметр stream
}
int main()
{
    cout << 10 << " " << setup << 10;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

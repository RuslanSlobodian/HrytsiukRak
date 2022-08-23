//Код програми 9.18. Демонстрація механізму використання функції get()

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

int main()
{
    char str[80];
    cout << "Введiть iм'я: ";
    cin.get(str, 79);

    cout << str << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

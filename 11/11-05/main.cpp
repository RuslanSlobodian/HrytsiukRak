//Код програми 11.5. Демонстрація механізму застосування покажчиків на функції

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

void hLine(int i)
{
    for(; i; i--) cout << "-";
    cout << endl;
}

void vLine(int i)
{
    for(; i; i--) cout << "|" << endl;
}

int main()
{
    void (*p)(int i);

    p = vLine; // Покажчик на функцію vLine()

    (*p)(4); // Виклик функції vLine()

    p = hLine; // Покажчик на функцію hLine()

    (*p)(5); // Виклик функції hLine()

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 10.10. Демонстрація механізму використання 	оператора static_cast

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

int main()
{
    int c;
    float f;
    f = 199.22F;
    c = static_cast<int> (f);

    cout << c;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

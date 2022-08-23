//Код програми 13.4. Демонстрація механізму використання директиви #if

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

#define MAX 100

int main()
{
#if MAX>10
    cout << "Потрiбна додаткова память" << endl;
#endif
    //...

    //system("PAUSE");
    return EXIT_SUCCESS;
}

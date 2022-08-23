//Код програми 13.5. Демонстрація механізму використання директив #if / #else

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

#define MAX 6

int main()
{
#if MAX>10
    cout << "Потрібна додаткова пам'ять" << endl;);
#else
    cout << "Достатньо наявної пам'ятi" << endl;
#endif
    //...

    //system("PAUSE");
    return EXIT_SUCCESS;
}

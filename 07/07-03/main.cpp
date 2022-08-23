//Код програми 7.3. Демонстрація механізму застосування шаблонної функції з двома узагальненими типами

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std;

template <class aType, class bType>
void FunC(aType a, bType b)
{
    cout << a << " " << b << endl;
}

int main()
{
    FunC(10, "Привiт");
    FunC(0.23, 10L);
    //system("PAUSE");
    return EXIT_SUCCESS;
}

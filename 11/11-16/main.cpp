//Код програми 11.16. Демонстрація механізму застосування специфікатора компонування функцій

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

extern "C" void cFun();

int main()
{
    cFun();
    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Ця функція буде скомпонована як С-функція.
void cFun()
{
    cout << "Ця функцiя скомпонована як С-функцiя" << endl;
}


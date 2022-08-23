//Код програми 11.12. Демонстрація механізму використання специфікатора explicit

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class myClass {		 // Оголошення класового типу
    int a;
public:
    myClass(int x) { a = x; }
    int Put() { return a; }
};
int main()
{
    myClass ObjA(4);
    cout << ObjA.Put();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 11.12. Демонстрація механізму використання специфікатора explicit

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class MyClass {		 // Оголошення класового типу
    int a;
public:
    objB(int x) { a = x; }
    int getData() { return a; }
};
int main()
{
    MyClass objB(4);
    cout << ObjA.getData();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

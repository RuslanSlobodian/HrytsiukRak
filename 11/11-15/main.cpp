//Код програми 11.15. Демонстрація механізму оголошення членів-даних класу звикористанням модифікатора const

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class MyClass { 		    // Оголошення класового типу
    const int a, b; // const-члени
public:
    // Ініціалізація членів a і b з використанням альтернативного синтаксису ініціалізації.
    MyClass(int x, int y): a(x), b(y) { }
    int PutA() { return a; }
    int PutB() { return b; }
};
int main()
{
    MyClass ObjA(7, 9), ObjB(5, 2);

    cout << "Значення ObjA = " << ObjA.PutA() << " i " << ObjA.PutB() << endl;
    cout << "Значення ObjB = " << ObjB.PutA() << " i " << ObjB.PutB() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

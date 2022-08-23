//Код програми 11.14. Демонстрація механізму ініціалізації членів-даних з використанням конструкторів классу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class myClass { 		     // Оголошення класового типу
    int a, b;
public:
    // Ініціалізація a і b у конструкторі myClass(), використовуючи 			звичайний синтаксис.
    myClass(int x, int y) { a = x; b = y; }
    int PutA() { return a; }
    int PutB() { return b; }
};
int main()
{
    myClass ObjA(7, 9), ObjB(5, 2);
    cout << "Значення об'єкта ObjA = " << ObjA.PutB() << " i " << 			ObjA.PutA() << endl;
    cout << "Значення об'єкта ObjB = " << ObjB.PutB() << " i " << 			ObjB.PutA() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

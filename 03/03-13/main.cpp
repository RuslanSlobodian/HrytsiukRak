//Код програми 3.13. Демонстрація механізму використання конструктора копії для ініціалізації одного об'єкта іншим

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class myClass { // Оголошення класового типу
    int *p;
public:
    myClass(int c) // Визначення звичайного конструктора
    { 	p = new int; *p = c;
        cout << "Видiлення p-пам'ятi звичайним конструктором" << endl;
    }
    myClass(const myClass &obj) // Визначення конструктора копії
    { 	p = new int; *p = *obj.p;
        cout << "Видiлення p-пам'ятi конструктором копiї" << endl;
    }
    ~myClass() { delete p; cout << "Звiльнення p-пам'ятi" << endl; }
};

int main()
{
    myClass ObjA(10); // Викликається звичайний конструктор.
    myClass ObjB = ObjA; // Викликається конструктор копії.

    //system("PAUSE");
    return EXIT_SUCCESS;
}

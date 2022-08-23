//Код програми 3.14. Демонстрація механізму використання конструктора копії для передачі об'єкта функції

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
    {	 p = new int; *p = *obj.p;
         cout << "Видiлення p-пам'ятi конструктором копiї" << endl;
    }
    ~myClass()
    { 	delete p;
        cout << "Звiльнення p-пам'ятi" << endl;
    }
    int Put() { return *p; }
};
// Ця функція приймає один об'єкт-параметр.
void Get(myClass obj)
{
    cout << "*p= " << obj.Put() << endl;
}
int main()
{
    myClass ObjA(10); // Створення об'єкта класу
    Get(ObjA);

    //system("PAUSE");
    return EXIT_SUCCESS;
}

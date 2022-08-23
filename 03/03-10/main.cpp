//Код програми 3.10. Демонстрація механізму вирішення проблеми при передачі об'єктів функціям,
//у яких динамічно виділяється та звільняється область пам'яті

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class myClass { // Оголошення класового типу
    int *p;
public:
    myClass(int c)
    {
        p = new int;
        *p = c;
        cout << "Видiлення p-пам'ятi звичайним конструктором" << endl;
    }
    ~myClass()
    {
        delete p; cout << "Звiльнення p-пам'ятi" << endl;
    }
    int Put() { return *p; }
};
// Ця функція НЕ створює проблем.__
void Get(myClass &obj) // Передача об'єкта за посиланням
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

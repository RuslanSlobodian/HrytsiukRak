//Код програми 2.7. Демонстрація механізму використання класу замість структури

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 		// Використання стандартного простору імен

class myClass { 			// Оголошення класового типу
    int c; 					// Закритий член за замовчуванням
public:
    int Put();
    void Get(int d);
};
int myClass::Put()
{
    return c;
}
void myClass::Get(int d)
{
    c = d;
}

int main()
{
    myClass Obj; 				// Створення об'єкта класу
    Obj.Get(10);
    cout << "c= " << Obj.Put() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

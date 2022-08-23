//Код програми 2.6. Демонстрація механізму використання структури для створення класу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 		// Використання стандартного простору імен

struct myStruct { 			// Оголошення структурного типу
    int Put(); 				// Ці члени відкриті (public)
    void Get(int d); 		// за замовчуванням.
private:
    int c;
};

int myStruct::Put()
{
    return c;
}
void myStruct::Get(int d)
{
    c = d;
}
int main()
{
    myStruct Obj; 		// Створення об'єкта структури
    Obj.Get(10);
    cout << "c= " << Obj.Put() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

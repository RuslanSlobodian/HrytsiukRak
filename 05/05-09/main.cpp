//Код програми 5.9. Демонстрація послідовності виконання конструкторів і деструкторів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class BaseClass {		 // Оголошення базового класу
public:
    BaseClass() 		{ cout << "Створення baseClass-об'єкта" << endl; }
    ~BaseClass() 	{ cout << "Руйнування baseClass-об'єкта" << endl; }
};

// Оголошення похідного класу
class Derived : public BaseClass {
public:
    Derived() { cout << "Створення derived-об'єкта" << endl; }
    ~Derived() { cout << "Руйнування derived-об'єкта" << endl; }
};

int main()
{
    Derived ObjD; // Створення об'єкта класу
    // Ніяких дій, окрім створення і руйнування об'єкта ObjD.

    //system("PAUSE");
    return EXIT_SUCCESS;
}

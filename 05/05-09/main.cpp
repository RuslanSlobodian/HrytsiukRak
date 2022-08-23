//Код програми 5.9. Демонстрація послідовності виконання конструкторів і деструкторів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class baseClass {		 // Оголошення базового класу
public:
    baseClass() 		{ cout << "Створення baseClass-об'єкта" << endl; }
    ~baseClass() 	{ cout << "Руйнування baseClass-об'єкта" << endl; }
};

// Оголошення похідного класу
class derived : public baseClass {
public:
    derived() { cout << "Створення derived-об'єкта" << endl; }
    ~derived() { cout << "Руйнування derived-об'єкта" << endl; }
};

int main()
{
    derived ObjD; // Створення об'єкта класу
    // Ніяких дій, окрім створення і руйнування об'єкта ObjD.

    //system("PAUSE");
    return EXIT_SUCCESS;
}

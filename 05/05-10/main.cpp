//Код програми 5.10. Демонстрація послідовності виконання конструкторів і деструкторівпри розширеній ієрархії класів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class baseClass		 { // Оголошення базового класу
public:
    baseClass()		 { cout << "Створення baseClass-об'єкта" << endl; }
    ~baseClass() 	 { cout << "Руйнування baseClass-об'єкта" << endl; }
};

// Оголошення похідного класу
class derivedA : public baseClass {
public:
    derivedA()		 { cout << "Створення derivedA-об'єкта" << endl; }
    ~derivedA() 	{ cout << "Руйнування derivedA-об'єкта" << endl; }
};

// Оголошення похідного класу
class derivedB : public derivedA {
public:
    derivedB() { cout << "Створення derivedB-об'єкта" << endl; }
    ~derivedB() { cout << "Руйнування derivedB-об'єкта" << endl; }
};

int main()
{
    derivedB ObjB; // Створення об'єкта класу
    // Створення і руйнування об'єкта ObjB.

    //system("PAUSE");
    return EXIT_SUCCESS;
}

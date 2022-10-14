//Код програми 5.11. Демонстрація послідовності виконання конструкторів і деструкторів під час успадкування декількох базових класів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class baseA {		 // Оголошення базового класу
public:
    baseA()		 { cout << "Створення baseA-об'єкта" << endl; }
    ~baseA()		 { cout << "Руйнування baseA-об'єкта" << endl; }
};

class baseB { // Оголошення базового класу
public:
    baseB()		 { cout << "Створення baseB-об'єкта" << endl; }
    ~baseB()		 { cout << "Руйнування baseB-об'єкта" << endl; }
};

// Оголошення похідного класу
class Derived : public baseA, public baseB {
public:
    Derived() 		{ cout << "Створення derived-об'єкта" << endl; }
    ~Derived()		 { cout << "Руйнування derived-об'єкта" << endl; 	}
};

int main()
{
    Derived ObjD; // Створення об'єкта класу
    // Створення і руйнування об'єкта ObjD.

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 2.2. Демонстрація механізму використання конструктора і деструктора

#include <iostream>		 		// Для потокового введення-виведення
#include <math.h>			 	// Для використання математичних функцій
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class myClass { 			     // Оголошення класового типу
    double a;
public:
    myClass(); 			     // Оголошення конструктора
    ~myClass(); 		     // Оголошення деструктора
    void Get(double, double); // Введення в об'єкт значення
    double Put(); 		     // Виведення з об'єкта значення
};
// Визначення конструктора.
myClass::myClass()
{
    a = 0; cout << "Об'єкт iнiцiалiзовано" << endl;
}
// Визначення деструктора.
myClass::~myClass()
{
    cout << "Об'єкт зруйновано" << endl;
}
// Введення в об'єкт значення.
void myClass::Get(double x, double y)
{
    double a1 = pow(x,1.3);
    double a2 = pow(fabs(3.2*x - y),0.4);
    double a3 = pow(pow(cos(a2),2),1./3);
    a = a1+a3;
}
// Виведення з об'єкта значення
double myClass::Put()
{
    return a;
}

int main()
{
    myClass ObjA, ObjB; 		// Створення двох об'єктів класу.
    double x = 2.6, y = 7.1;
    ObjA.Get(x,y); ObjB.Get(x+y,y/x);
    cout << "Вмiст об'єкта ObjA: " << ObjA.Put() << endl;
    cout << "Вмiст об'єкта ObjB: " << ObjB.Put() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

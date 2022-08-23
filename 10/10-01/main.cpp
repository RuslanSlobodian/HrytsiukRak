//Код програми 10.1. Демонстрація механізму використання оператора typeid

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <typeinfo> 		// Для динамічної ідентифікації типів

using namespace std; 			// Використання стандартного простору імен

class myClass { 			// Оголошення класового типу
    //. . .
};
int main()
{
    int c, d;
    float f;
    myClass obj;
    cout << "Тип змiнної c: " << typeid(c).name() << endl;
    cout << "Тип змiнної f: " << typeid(f).name() << endl;
    cout << "Тип змiнної obj: " << typeid(obj).name() << endl << endl;

    if(typeid(c) == typeid(d))
        cout << "Типи змiнних c та d однаковi" << endl;
    if(typeid(c) != typeid(f))
        cout << "Типи змiнних c та f неоднаковi" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

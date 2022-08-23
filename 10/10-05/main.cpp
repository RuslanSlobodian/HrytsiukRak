//Код програми 10.5. Демонстрація механізму застосування оператора typeid до шаблонних класів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <typeinfo> 		// Для динамічної ідентифікації типів

using namespace std; 			// Використання стандартного простору імен

template <class aType> class myClass { // Оголошення класового типу
    aType a;
public:
    myClass(aType c) { a = c; }
    //. . .
};

int main()
{
    myClass<int> ObjA(10), ObjB(9);
    myClass<double> ObjC(7.2);

    cout << "Об'єкт ObjA має тип ";
    cout << typeid(ObjA).name() << endl;

    cout << "Об'єкт ObjB має тип ";
    cout << typeid(ObjB).name() << endl;

    cout << "Об'єкт ObjC має тип ";
    cout << typeid(ObjC).name() << endl;

    cout << endl;

    if(typeid(ObjA) == typeid(ObjB))
        cout << "Об'єкти ObjA i ObjB мають однаковий тип" << 				endl;
    if(typeid(ObjA) == typeid(ObjC))
        cout << "Помилка" << endl;
    else
        cout << "Об'єкти ObjA i ObjC мають рiзнi типи" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

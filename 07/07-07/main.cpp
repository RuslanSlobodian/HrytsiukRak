//Код програми 7.7. Демонстрація механізму створення класу з двома узагальненими типами даних

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std;

template <class aType, class bType> class myClass {
    aType c;
    bType d;
public:
    myClass(aType ObjA, bType ObjB) { c = ObjA; d = ObjB; }
    void showType()
    {cout << "c= " << c << "; d= " << d << endl; }
};

int main()
{
    myClass<int, double> ObjA(10, 0.23);
    myClass<char, char *> ObjB('x', "Це тест.");
    ObjA.showType(); // Відображення int- і double-значень
    ObjB.showType (); // Відображення значень типу char і char *

    //system("PAUSE");
    return EXIT_SUCCESS;
}

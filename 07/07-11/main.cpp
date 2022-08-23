//Код програми 7.11. Демонстрація безпосередньо заданої спеціалізації класів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std;

template <class tType> class myClass { // Оголошення класового типу
    tType x;
public:
    myClass(tType ObjA) { cout << "У тiлi узагальненого класу myClass" << endl; x = ObjA; }
    tType getX() { return x; }
};
// Безпосередня спеціалізація для типу int.
template <> class myClass<int> {
    int x;
public:
    myClass(int a) { cout << "У тiлi спецiалiзацiї myClass<int>" << endl; x = a * a; }
    int getX() { return x; }
};

int main()
{
    myClass<double> ObjD(10.1);
    cout << "double: " << ObjD.getX() << endl << endl;
    myClass<int> ObjI(5);
    cout << "int: " << ObjI.getX() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

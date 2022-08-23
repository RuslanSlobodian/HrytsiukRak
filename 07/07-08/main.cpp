//Код програми 7.8. Демонстрація механізму створення та використання узагальненого класу для організації безпечного масиву

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std;

const int size = 10;
template <class aType> class arrClass { // Оголошення класового типу
    aType aMas[size];
public:
    arrClass() { for(int i=0; i<size; i++) aMas[i] = i; }
    aType &operator[](int i);
};
// Забезпечення контролю меж для класу aType.
template <class aType> aType &arrClass<aType>::operator[](int i)
{
    if(i<0 || i> size-1)
    {
        cout << "Значення iндексу " << i << " за межами масиву" << endl;
        exit(1);
    }
    return aMas[i];
}

int main()
{
    arrClass<int> ObjI; // Масив int-значень
    arrClass<double> ObjD; // Масив double-значень
    cout << "Масив int-значень: ";
    for(int i=0; i<size; i++) ObjI[i] = i;
    for(int i=0; i<size; i++) cout << ObjI[i] << " ";
    cout << endl;
    cout << "Масив double-значень: ";
    for(int i=0; i<size; i++) ObjD[i] = i/3.0;
    for(int i=0; i<size; i++) cout << ObjD[i] << " ";
    cout << endl;
    ObjI[12] = 100; // Помилка, спроба вийти за межі масиву!

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 7.9. Демонстрація механізму використання в узагальнених класах аргументів, що не є узагальненими типами

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std;

// Тут елемент int size - це аргумент, що не є узагальненими типом.
template <class aType, int size> class arrClass {
    aType aMas[size]; // В аргументі size передається розмір масиву.__
public:
    arrClass() { for(int i=0; i<size; i++) aMas[i] = i; }
    aType &operator[](int i);
};
// Забезпечення контролю меж для класу aType.
template <class aType, int size> aType & arrClass<aType, size>::operator[](int i)
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
    arrClass<int, 10> ObjI; // 10-елементний масив цілих чисел
    arrClass<double, 15> ObjD; // 15-елементний масив double-значень
    cout << "Масив цiлих чисел: ";
    for(int i=0; i<10; i++) ObjI[i] = i;
    for(int i=0; i<10; i++) cout << ObjI[i] << " ";
    cout << endl;
    cout << "Масив double-значень: ";
    for(int i=0; i<15; i++) ObjD[i] = i/3.0;
    for(int i=0; i<15; i++) cout << ObjD[i] << " ";
    cout << endl;
    ObjI[12] = 100; // Помилка тривалості виконання!

    //system("PAUSE");
    return EXIT_SUCCESS;
}

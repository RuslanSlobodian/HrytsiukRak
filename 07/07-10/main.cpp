//Код програми 7.10. Демонстрація механізму використання шаблонних аргументів за замовчуванням

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std;

// Тут параметр aType за замовчуванням приймає тип int, a параметр
// size за замовчуванням встановлюється таким, що дорівнює 10.
template <class aType=int, int size=10> class arrClass {
    aType aMas[size]; // Через параметр size передається розмір масиву.
public:
    arrClass() { for(int i=0; i<size; i++) aMas[i] = i; }
    aType &operator[](int i);
};
// Забезпечення контролю меж для класу aType.
template <class aType, int size> aType &arrClass<aType, size>::operator[](int i)
{
    if(i<0 || i> size-1) {
        cout << "Значення iндексу " << i << " за межами масиву" << endl;
        exit(1);
    }
    return aMas[i];
}
int main()
{
    arrClass<int, 100> intMas; // 100-елементний масив цілих чисел
    arrClass<double> doubleMas; // 10-елементний масив double-значень
    // (розмір масиву встановлено за замовчуванням)
    arrClass<> defMas; // 10-елементний масив int-значень
    // (розмір і тип int встановлені за замовчуванням)
    cout << "Масив цiлих чисел: ";
    for(int i=0; i<100; i++) intMas[i] = i;
    for(int i=0; i<100; i++) cout << intMas[i] << " ";
    cout << endl;
    cout << "Масив double-значень: ";
    for(int i=0; i<10; i++) doubleMas[i] = i/3.0;
    for(int i=0; i<10; i++) cout << doubleMas[i] << " ";
    cout << endl;
    cout << "Масив за замовчуванням: ";
    for(int i=0; i<10; i++) defMas[i] = i;
    for(int i=0; i<10; i++) cout << defMas[i] << " ";
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

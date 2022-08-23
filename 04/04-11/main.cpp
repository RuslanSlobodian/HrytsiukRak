//Код програми 4.11. Демонстрація прикладу організації безпечного масиву

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

const int size = 3;
class aClass { // Оголошення класового типу
    int aMas[size];
public:
    aClass() { for(int i=0; i<size; i++) aMas[i] = i*i; }
    int &operator[](int i);
};
// Забезпечення контролю потрапляння індексу масиву
// в допустимий інтервал його перебування.
int &aClass::operator[](int i)
{
    if(i<0 || i> size-1)
    {
        cout << endl << "Значення iндексу " << i <<	" виходить за межi допустимого iнтервалу" << endl;
        system("PAUSE");
        exit(1);
    }
    return aMas[i];
}

int main()
{
    aClass ObjA;
    cout << "Значення елементiв масиву <A>:" << endl;
    for(int i=0; i<3; i++)
        cout << "aMas[" << i << "]= " << ObjA[i] << endl;
    ObjA[2] = 25; // Оператор "[]" знаходиться в лівій частині.
    cout << endl << "aMas[2]= " << ObjA[2]; // Відображається число 25.
    ObjA[3] = 44; // Виникає помилка тривалості виконання, оскільки
    // значення індексу 3 виходить за межі допустимого інтервалу.

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 4.9. Демонстрація механізму перевизначення оператора індексації елементів масиву "[]"

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

const int size = 3;

class aClass { // Оголошення класового типу
    int aMas[size];
public:
    aClass() { for(int i=0; i<size; i++) aMas[i] = i*i; }
    int operator[](int i) {return aMas[i]; }
};

int main()
{
    aClass ObjA;
    cout << "aMas[2]= " << ObjA[2] << endl; // Відображає число 4
    cout << "Значення елементiв масиву <A>:" << endl;
    for(int i=0; i<3; i++)
        cout << "aMas[" << i << "]= " << ObjA[i] << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

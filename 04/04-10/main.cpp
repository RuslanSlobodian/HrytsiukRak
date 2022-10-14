/*
 * Код програми 4.10. Демонстрація механізму перевизначення оператора індексації
 * елементів масиву "[]" як зліва, так і праворуч від оператора присвоєння
 */

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

const int SIZE = 3;

class FirstClass {              // Оголошення класового типу
    int aMas[SIZE];
public:
    FirstClass() {
        for(int i = 0; i < SIZE; i++) {
            aMas[i] = i*i;
        }
    }
    int &operator[](int i) {
        return aMas[i];
    }
};

int main() {
    FirstClass objectA;
    cout << "Значення елементiв масиву <A>:" << endl;
    for(int i=0; i<3; i++) {
        cout << "aMas[" << i << "]= " << objectA[i] << endl;
    }
    // Оператор "[]" знаходиться зліва від оператора присвоєння "="
    objectA[2] = 25;
    cout << endl << "aMas[2]= " << objectA[2]; // Тепер відображається число 25

    //system("PAUSE");
    return EXIT_SUCCESS;
}

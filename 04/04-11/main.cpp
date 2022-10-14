// Код програми 4.11. Демонстрація прикладу організації безпечного масиву

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

const int SIZE = 3;

class FirstClass {              // Оголошення класового типу
    int aMas[SIZE];
public:
    FirstClass() {
        for(int i = 0; i < SIZE; i++) {
            aMas[i] = i * i;
        }
    }
    int &operator[](int i);
};

// Забезпечення контролю потрапляння індексу масиву в допустимий інтервал його перебування
int &FirstClass::operator[](int i) {
    if(i < 0 || i > (SIZE - 1)) {
        cout << endl << "Значення iндексу " << i <<	" виходить за межi допустимого iнтервалу" << endl;
        system("PAUSE");
        exit(1);
    }
    return aMas[i];
}

int main() {
    FirstClass objectA;
    cout << "Значення елементiв масиву <A>:" << endl;
    for(int i=0; i<3; i++) {
        cout << "aMas[" << i << "]= " << objectA[i] << endl;
    }
    objectA[2] = 25;            // Оператор "[]" знаходиться в лівій частині
    cout << endl << "aMas[2]= " << objectA[2]; // Відображається число 25
    objectA[3] = 44;            // Виникає помилка періоду виконання, оскільки
                                // значення індексу 3 виходить за межі допустимого інтервалу

    //system("PAUSE");
    return EXIT_SUCCESS;
}

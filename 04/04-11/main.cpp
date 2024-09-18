// Код програми 4.11. Демонстрація прикладу організації безпечного масиву

#include <iostream>
#include <cstdlib>

using namespace std;

const int SIZE = 3;

class ArrayClass {              // Оголошення класового типу
    int array[SIZE];
public:
    ArrayClass() {
        for (int i = 0; i < SIZE; i++) {
            array[i] = i * i;
        }
    }

    int& operator[](int i);
};

// Забезпечення контролю потрапляння індексу масиву в допустимий інтервал його перебування
int& ArrayClass::operator[](int i) {
    if (i < 0 || i > (SIZE - 1)) {
        cout << endl << "Значення iндексу " << i << " виходить за межi допустимого iнтервалу" << endl;
        system("PAUSE");
        exit(1);
    }
    return array[i];
}

int main() {
    system("chcp 65001");
    ArrayClass objectA;
    cout << "Значення елементiв масиву <A>:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "array[" << i << "]= " << objectA[i] << endl;
    }
    objectA[2] = 25;            // Оператор "[]" знаходиться в лівій частині
    cout << endl << "array[2]= " << objectA[2]; // Відображається число 25
    objectA[3] = 44;            // Виникає помилка періоду виконання, оскільки
    // значення індексу 3 виходить за межі допустимого інтервалу

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Код програми 4.10. Демонстрація механізму перевизначення оператора індексації елементів масиву "[]"
// як зліва, так і праворуч від оператора присвоєння

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

    int &operator[](int i) {
        return array[i];
    }
};

int main() {
    system("chcp 65001");
    ArrayClass objectA;
    cout << "Значення елементiв масиву <A>:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "array[" << i << "]= " << objectA[i] << endl;
    }
    // Оператор "[]" знаходиться зліва від оператора присвоєння "="
    objectA[2] = 25;
    cout << endl << "array[2]= " << objectA[2]; // Тепер відображається число 25

    //system("PAUSE");
    return EXIT_SUCCESS;
}

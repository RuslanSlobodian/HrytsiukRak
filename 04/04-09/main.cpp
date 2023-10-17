// Код програми 4.9. Демонстрація механізму перевизначення оператора індексації елементів масиву "[]"

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

    int operator[](int i) {
        return array[i];
    }
};

int main() {
    system("chcp 65001");
    ArrayClass objectA;
    cout << "array[2]= " << objectA[2] << endl; // Відображає число 4
    cout << "Значення елементiв масиву <A>:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "array[" << i << "]= " << objectA[i] << endl;
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

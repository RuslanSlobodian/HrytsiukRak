// Код програми 7.8. Демонстрація механізму створення та використання узагальненого класу для організації безпечного масиву

#include <iostream>
#include <cstdlib>

using namespace std;

const int SIZE = 10;

template<typename T>
class ArrClass {                // Оголошення шаблонного класу безпечного масиву
    T array[SIZE];
public:
    ArrClass() { for (int i = 0; i < SIZE; i++) array[i] = i; }

    T& operator[](int i);
};

// Забезпечення контролю меж для класу ArrClass
template<typename T>
T& ArrClass<T>::operator[](int i) {
    if (i < 0 || i > SIZE - 1) {
        cout << "Значення iндексу " << i << " за межами масиву" << endl;
        exit(1);
    }
    return array[i];
}

int main() {
    system("chcp 65001");
    ArrClass<int> arrayOfInt;   // Масив int-значень
    ArrClass<double> arrayOfDouble; // Масив double-значень
    cout << "Масив int-значень: ";
    for (int i = 0; i < SIZE; i++) arrayOfInt[i] = i;
    for (int i = 0; i < SIZE; i++) cout << arrayOfInt[i] << " ";
    cout << endl;
    cout << "Масив double-значень: ";
    for (int i = 0; i < SIZE; i++) arrayOfDouble[i] = i / 3.0;
    for (int i = 0; i < SIZE; i++) cout << arrayOfDouble[i] << " ";
    cout << endl;
    arrayOfInt[12] = 100;       // Помилка, спроба вийти за межі масиву!

    //system("PAUSE");
    return EXIT_SUCCESS;
}

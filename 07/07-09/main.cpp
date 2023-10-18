// Код програми 7.9. Демонстрація механізму використання в шаблонних класах аргументів, що не є узагальненими типами

#include <iostream>
#include <cstdlib>

using namespace std;

// Тут елемент int size - це аргумент, що не є узагальненими типом
template<typename T, int size>
class ArrClass {
    T array[size];               // В аргументі size передається розмір масиву
public:
    ArrClass() { for (int i = 0; i < size; i++) array[i] = i; }

    T& operator[](int i);
};

// Забезпечення контролю меж для класу ArrClass
template<typename T, int size>
T& ArrClass<T, size>::operator[](int i) {
    if (i < 0 || i > size - 1) {
        cout << "Значення iндексу " << i << " за межами масиву" << endl;
        exit(1);
    }
    return array[i];
}

int main() {
    system("chcp 65001");
    ArrClass<int, 10> arrayOfInt; // 10-елементний масив цілих чисел
    ArrClass<double, 15> arrayOfDouble;  // 15-елементний масив double-значень
    cout << "Масив цiлих чисел: ";
    for (int i = 0; i < 10; i++) arrayOfInt[i] = i;
    for (int i = 0; i < 10; i++) cout << arrayOfInt[i] << " ";
    cout << endl;
    cout << "Масив double-значень: ";
    for (int i = 0; i < 15; i++) arrayOfDouble[i] = i / 3.0;
    for (int i = 0; i < 15; i++) cout << arrayOfDouble[i] << " ";
    cout << endl;
    arrayOfInt[12] = 100; // Помилка тривалості виконання!

    //system("PAUSE");
    return EXIT_SUCCESS;
}

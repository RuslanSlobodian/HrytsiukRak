// Код програми 7.10. Демонстрація механізму використання шаблонних аргументів за замовчуванням

#include <iostream>
#include <cstdlib>

using namespace std;

// Тут параметр T за замовчуванням приймає тип int, a параметр size
// за замовчуванням встановлюється таким, що дорівнює 10
template<typename T = int, int size = 10>
class ArrClass {
    T array[size];               // Через параметр size передається розмір масиву
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
    ArrClass<int, 100> arrayOfInt;  // 100-елементний масив цілих чисел
    ArrClass<double> arrayOfDouble; // 10-елементний масив double-значень (розмір масиву встановлено за замовчуванням)
    ArrClass<> defMas; // 10-елементний масив int-значень (розмір і тип int встановлені за замовчуванням)

    cout << "Масив цiлих чисел: ";
    for (int i = 0; i < 100; i++) arrayOfInt[i] = i;
    for (int i = 0; i < 100; i++) cout << arrayOfInt[i] << " ";
    cout << endl;
    cout << "Масив double-значень: ";
    for (int i = 0; i < 10; i++) arrayOfDouble[i] = i / 3.0;
    for (int i = 0; i < 10; i++) cout << arrayOfDouble[i] << " ";
    cout << endl;
    cout << "Масив за замовчуванням: ";
    for (int i = 0; i < 10; i++) defMas[i] = i;
    for (int i = 0; i < 10; i++) cout << defMas[i] << " ";
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Код програми 12.8 Демонстрація механізму сортування списку

#include <iostream>
#include <cstdlib>
#include <list>                 // Для роботи зі списками

using namespace std;

int main() {
    system("chcp 65001");
    list<int> listOfIntegers;   // Створення порожнього списку
    // Створення списку випадково вибраних цілих чисел
    srand(time(nullptr));
    for (int i = 0; i < 10; i++)
        listOfIntegers.push_back(rand());

    // Відображення початкового вмісту списку

    cout << "Початковий вмiст списку:" << endl;
    list<int>::iterator ptr = listOfIntegers.begin();
    while (ptr != listOfIntegers.end()) {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl << endl;

    // Сортування списку
    listOfIntegers.sort();

    // Відображення відсортованого вмісту списку
    cout << "Вiдсортований вмiст списку:" << endl;
    ptr = listOfIntegers.begin();
    while (ptr != listOfIntegers.end()) {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

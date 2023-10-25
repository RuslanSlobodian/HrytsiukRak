// Код програми 12.16. Демонстрація механізму використання алгоритму transform()

#include <iostream>
#include <cstdlib>
#include <list>                 // Для роботи зі списками
#include <algorithm>            // Для роботи з алгоритмами бібліотеки STL

using namespace std;

// Проста функція перетворення
int xForm(int i) {
    return i * i;               // Квадрат початкового значення
}

int main() {
    system("chcp 65001");
    list<int> xList;
    // Поміщаємо значення у список
    for (int i = 0; i < 10; i++)
        xList.push_back(i);
    cout << "Початковий список xList: ";
    list<int>::iterator ptr = xList.begin();
    while (ptr != xList.end()) {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;

    // Перетворення списку xList
    transform(xList.begin(), xList.end(), xList.begin(), xForm);

    cout << "Перетворений список xList: ";
    ptr = xList.begin();
    while (ptr != xList.end()) {
        cout << *ptr << " ";
        ptr++;
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

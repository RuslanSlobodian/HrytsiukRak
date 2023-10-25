// Код програми 12.15. Демонстрація механізму використання алгоритму reverse

#include <iostream>
#include <cstdlib>
#include <vector>               // Для роботи з контейнерним класом "Вектор"
#include <algorithm>            // Для роботи з алгоритмами бібліотеки STL

using namespace std;

int main() {
    system("chcp 65001");
    vector<int> vectorOfIntegers;
    unsigned int i;

    for (i = 0; i < 10; i++)
        vectorOfIntegers.push_back(i);

    cout << "Початкова послiдовнiсть: ";
    for (i = 0; i < vectorOfIntegers.size(); i++)
        cout << vectorOfIntegers[i] << " ";
    cout << endl;

    reverse(vectorOfIntegers.begin(), vectorOfIntegers.end());

    cout << "Реверсована послiдовнiсть: ";
    for (i = 0; i < vectorOfIntegers.size(); i++)
        cout << vectorOfIntegers[i] << " ";

    //system("PAUSE");
    return EXIT_SUCCESS;
}

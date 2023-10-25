// Код програми 12.14. Демонстрація механізму використання алгоритмів remove_copy і replace_copy

#include <iostream>
#include <cstdlib>
#include <vector>               // Для роботи з контейнерним класом "Вектор"
#include <algorithm>            // Для роботи з алгоритмами бібліотеки STL


using namespace std;

int main() {
    system("chcp 65001");
    char str[] = "This is a very simple test.";
    vector<char> vectorA;
    vector<char> vectorB(30);

    for (int i = 0; str[i]; i++)
        vectorA.push_back(str[i]);

    // **** Демонстрація алгоритму remove_copy ****

    cout << "Вхiдна послiдовнiсть: ";
    for (int i = 0; i < vectorA.size(); i++)
        cout << vectorA[i];
    cout << endl;

    // Видаляємо всі букви 's'
    remove_copy(vectorA.begin(), vectorA.end(), vectorB.begin(), 's');

    cout << "Пiсля видалення букв 's': ";
    for (int i = 0; vectorB[i]; i++)
        cout << vectorB[i];
    cout << endl << endl;

    // **** Демонстрація алгоритму replace_copy ****

    cout << "Вхiдна послiдовнiсть: ";
    for (int i = 0; i < vectorA.size(); i++)
        cout << vectorA[i];
    cout << endl;

    // Замінюємо букви 's' буквами 'S'
    replace_copy(vectorA.begin(), vectorA.end(), vectorB.begin(), 's', 'S');

    cout << "Пiсля замiни букв 's' буквами 'S': ";
    for (int i = 0; vectorB[i]; i++)
        cout << vectorB[i];
    cout << endl << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

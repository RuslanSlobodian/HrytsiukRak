// Код програми 12.9. Демонстрація механізму об'єднання двох списків

#include <iostream>
#include <cstdlib>
#include <list>                 // Для роботи зі списками

using namespace std;

int main() {
    system("chcp 65001");
    list<char> listA, listB;    // Створення двох порожніх списків

    // Створення двох списків з випадково вибраними цілими числами
    srand(time(nullptr));
    for (int i = 0; i < 10; i += 2)
        listA.push_back('A' + i);
    for (int i = 1; i < 11; i += 2)
        listB.push_back('A' + i);

    // Відображення початкового вмісту першого списку
    cout << "Вмiст списку listA: ";
    list<char>::iterator ptr = listA.begin();
    while (ptr != listA.end()) {
        cout << *ptr;
        ptr++;
    }
    cout << endl << endl;

    // Відображення початкового вмісту другого списку
    cout << "Вмiст списку listB: ";
    ptr = listB.begin();
    while (ptr != listB.end()) {
        cout << *ptr;
        ptr++;
    }
    cout << endl << endl;

    // Тепер об'єднуємо ці два списки
    listA.merge(listB);
    if (listB.empty()) cout << "Список listB тепер порожнiй" << endl;

    // Відображення об'єднаного вмісту першого списку
    cout << "Вмiст списку listA пiсля об'єднання:" << endl;
    ptr = listA.begin();
    while (ptr != listA.end()) {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

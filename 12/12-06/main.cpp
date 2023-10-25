// Код програми 12.6. Демонстрація механізму використання базових операцій для роботи з списком

#include <iostream>
#include <cstdlib>
#include <list>                 // Для роботи зі списками

using namespace std;

int main() {
    system("chcp 65001");
    std::list<char> listOfChars;     // Створення порожнього списку
    // Поміщаємо значення у список
    for (int i = 0; i < 10; i++)
        listOfChars.push_back('A' + i);

    // Відображаємо початковий розміру списку
    cout << "Розмiр = " << listOfChars.size() << endl;

    // Відображаємо початковий вміст списку
    cout << "Вмiст: ";
    list<char>::iterator ptr = listOfChars.begin();
    // Отримуємо доступ до вмісту списку за допомогою ітератора
    while (ptr != listOfChars.end()) {
        cout << *ptr << " ";
        ptr++;
        cout << endl;
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

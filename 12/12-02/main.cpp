// Код програми 12.2. Демонстрація механізму доступу до елементів вектора за допомогою ітератора

#include <iostream>
#include <cstdlib>
#include <vector>               // Для роботи з контейнерним класом "Вектор"

using namespace std;

int main() {
    vector<char> vectorOfChars; // Побудова вектора нульової довжини

    // Поміщаємо значення у вектор
    for (int i = 0; i < 10; i++) {
        vectorOfChars.push_back('A' + i);
    }

    // Отримуємо доступ до вмісту вектора за допомогою індексу
    for (int i = 0; i < 10; i++) {
        cout << vectorOfChars[i] << " ";
    }
    cout << endl;

    // Отримуємо доступ до вмісту вектора за допомогою ітератора
    vector<char>::iterator ptr = vectorOfChars.begin();
    while (ptr != vectorOfChars.end()) {
        cout << *ptr << " ";
        ptr++;
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

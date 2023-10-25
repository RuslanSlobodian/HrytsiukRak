// Код програми 12.3. Демонстрація механізму вставлення елементів у вектор і видалення їх з нього

#include <iostream>
#include <cstdlib>
#include <vector>               // Для роботи з контейнерним класом "Вектор"

using namespace std;

int main() {
    system("chcp 65001");
    vector<char> vectorOfChars; // Побудова вектора нульової довжини

    // Поміщаємо значення у вектор
    for (int i = 0; i < 10; i++) {
        vectorOfChars.push_back('A' + i);
    }

    // Відображаємо початковий вміст вектора
    cout << "Розмiр = " << vectorOfChars.size() << endl;
    cout << "Початковий вмiст вектора:" << endl;
    for (int i = 0; i < vectorOfChars.size(); i++) {
        cout << vectorOfChars[i] << " ";
    }
    cout << endl;

    // Отримуємо доступ до вмісту вектора за допомогою ітератора
    vector<char>::iterator ptr = vectorOfChars.begin();
    ptr += 2; // Вказівник на 3-й елемент вектора

    // Вставляємо 10 символів 'x' у вектор vectorOfChars
    vectorOfChars.insert(ptr, 10, 'x');

    // Відображаємо вміст вектора після вставлення символів
    cout << "Розмiр вектора пiсля вставлення = " << vectorOfChars.size() << endl;
    cout << "Вмiст вектора пiсля вставлення:" << endl;
    for (int i = 0; i < vectorOfChars.size(); i++) {
        cout << vectorOfChars[i] << " ";
    }
    cout << endl;

    // Видалення вміщених елементів
    ptr = vectorOfChars.begin();
    ptr += 2;                         // Вказівник на 3-й елемент вектора
    vectorOfChars.erase(ptr, ptr + 10); // Видаляємо 10 елементів підряд

    // Відображаємо вміст вектора після видалення символів
    cout << "Розмiр вектора пiсля видалення символiв = " << vectorOfChars.size() << endl;
    cout << "Вмiст вектора пiсля видалення символiв:" << endl;
    for (int i = 0; i < vectorOfChars.size(); i++) {
        cout << vectorOfChars[i] << " ";
    }
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

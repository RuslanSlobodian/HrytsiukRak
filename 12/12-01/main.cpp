// Код програми 12.1. Демонстрація механізму базової поведінки вектора

#include <iostream>
#include <cstdlib>
#include <vector>               // Для роботи з контейнерним класом "Вектор"

using namespace std;

int main() {
    system("chcp 65001");
    // Створення вектора нульової довжини
    std::vector<int> vectorOfIntegers;

    // Відображаємо початковий розмір вектора
    cout << "Розмiр = " << vectorOfIntegers.size() << endl;

    // Поміщаємо значення у кінець вектора і розмір вектора за потреби збільшуватиметься
    for (int i = 0; i < 10; i++) {
        vectorOfIntegers.push_back(i);
    }

    // Відображаємо поточний розмір вектора vectorOfIntegers
    cout << "Новий розмiр = " << vectorOfIntegers.size() << endl;

    // Відображаємо вміст вектора
    cout << "Поточний вмiст:" << endl;
    for (int i = 0; i < vectorOfIntegers.size(); i++) {
        cout << vectorOfIntegers[i] << " ";
    }
    cout << endl;


    // Поміщаємо у кінець вектора нові значення і розмір вектора за потреби збільшуватиметься
    for (int i = 0; i < 10; i++) {
        vectorOfIntegers.push_back(i + 10);
    }
    // Відображаємо поточний розмір вектора vectorOfIntegers
    cout << "Новий розмiр = " << vectorOfIntegers.size() << endl;

    // Відображаємо новий вміст вектора
    cout << "Новий вмiст:" << endl;
    for (int i = 0; i < vectorOfIntegers.size(); i++) cout << vectorOfIntegers[i] << " ";
    cout << endl;

    // Змінюємо вміст вектора
    for (int i = 0; i < vectorOfIntegers.size(); i++) {
        vectorOfIntegers[i] = vectorOfIntegers[i] + vectorOfIntegers[i];
    }

    // Відображаємо вміст вектора
    cout << "Вмiст подвоєно:" << endl;
    for (int i = 0; i < vectorOfIntegers.size(); i++) {
        cout << vectorOfIntegers[i] << " ";
    }
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

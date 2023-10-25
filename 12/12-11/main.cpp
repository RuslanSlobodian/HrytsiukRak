// Код програми 12.11. Демонстрація механізму використання простого відображення

#include <iostream>
#include <cstdlib>
#include <map>                  // Для роботи з асоціативними контейнерами

using namespace std;

int main() {
    system("chcp 65001");
    std::map<char, int> mapA;   // Створення порожнього відображення

    // Поміщаємо пари у відображення
    for (int i = 0; i < 10; i++) {
        mapA.insert(std::pair<char, int>('A' + i, i));
    }
    char ch;
    cout << "Введiть ключ: ";
    cin >> ch;

    std::map<char, int>::iterator ptr;
    // Знаходимо значення за заданим ключем
    ptr = mapA.find(ch);
    if (ptr != mapA.end())
        cout << ptr->second;
    else
        cout << "Такого ключа у вiдображеннi немає" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

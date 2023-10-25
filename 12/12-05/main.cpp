// Код програми 12.5. Демонстрація механізму використання ітераторів для вставлення елементів одного вектора у інший

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
    system("chcp 65001");
    vector<char> vectorA;
    vector<char> vectorB;

    // Поміщаємо значення у вектор
    for (int i = 0; i < 10; i++)
        vectorA.push_back('A' + i);

    // Відображаємо початковий вміст вектора
    cout << "Початковий вмiст вектора:" << endl;
    for (int i = 0; i < vectorA.size(); i++)
        cout << vectorA[i] << " ";
    cout << endl << endl;

    // Ініціалізуємо другий вектор
    char str[] = "-STL -- це сила!-";
    for (int i = 0; str[i]; i++)
        vectorB.push_back(str[i]);

    // Отримуємо ітератори для середини вектора vectorA,
    // а також початку і кінця вектора vectorB
    vector<char>::iterator ptr = vectorA.begin() + 5;
    vector<char>::iterator ptr2start = vectorB.begin();
    vector<char>::iterator ptr2end = vectorB.end();

    // Вставляємо вектор vectorB у вектор vectorA
    vectorA.insert(ptr, ptr2start, ptr2end);

    // Відображаємо результат вставлення
    cout << "Вмiст вектора vectorA пiсля вставлення: " << endl;
    for (int i = 0; i < vectorA.size(); i++)
        cout << vectorA[i] << " ";
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

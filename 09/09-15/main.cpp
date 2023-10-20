// Код програми 9.15. Демонстрація механізму використання функцій read() і write()

#include <iostream>
#include <cstdlib>
#include <fstream>              // Для роботи з файлами

using namespace std;

int main() {
    system("chcp 65001");
    int numbers[5] = {1, 2, 3, 4, 5};
    int i;

    ofstream outStream("test", ios::out | ios::binary);
    if (!outStream) {
        cout << "Не вдається вiдкрити файл" << endl;
        return 1;
    }
    outStream.write((char*) &numbers, sizeof numbers);
    outStream.close();

    for (i = 0; i < 5; i++) numbers[i] = 0;   // Очищує масив

    ifstream inStream("test", ios::in | ios::binary);
    if (!inStream) {
        cout << "Не вдається вiдкрити файл" << endl;
        return 1;
    }
    inStream.read((char*) &numbers, sizeof numbers);
    for (i = 0; i < 5; i++)     // Відображаємо значення, зчитані з файлу
        cout << numbers[i] << " ";
    inStream.close();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

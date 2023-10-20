// Код програми 9.14. Демонстрація механізму використання функції put() для запису рядка у файл

#include <iostream>
#include <cstdlib>
#include <fstream>              // Для роботи з файлами

using namespace std;

int main() {
    system("chcp 65001");
    const char* p = "Всiм привiт!";

    ofstream outStream("test", ios::out | ios::binary);

    if (!outStream) {
        cout << "Не вдається вiдкрити файл" << endl;
        return 1;
    }
    while (*p) outStream.put(*p++);

    outStream.close();
    //system("PAUSE");
    return EXIT_SUCCESS;
}

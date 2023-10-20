// Код програми 9.11. Демонстрація механізму запису даних у файл

#include <iostream>
#include <cstdlib>
#include <fstream>              // Для роботи з файлами

using namespace std;

int main() {
    system("chcp 65001");
    ofstream outStream("test");
    if (!outStream) {
        cout << "Не вдається відкрити файл" << endl;
        return 1;
    }
    outStream << 10 << " " << 123.23 << endl;
    outStream << "Це короткий текстовий файл.";

    outStream.close();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

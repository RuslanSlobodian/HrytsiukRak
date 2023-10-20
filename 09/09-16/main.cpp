// Код програми 9.16. Демонстрація механізму виявлення кінця файлу

#include <iostream>
#include <cstdlib>
#include <fstream>              // Для роботи з файлами

using namespace std;

int main(int argc, char* argv[]) {
    system("chcp 65001");
    char ch;
    if (argc != 2) {
        cout << "Застосування: iм'я_програми <iм'я_файлу>" << endl;
        return 1;
    }
    ifstream inStream(argv[1], ios::in | ios::binary);
    if (!inStream) {
        cout << "Не вдається вiдкрити файл" << endl;
        return 1;
    }
    while (!inStream.eof()) {   // Використання функції eof()
        inStream.get(ch);
        if (!inStream.eof()) cout << ch;
    }
    inStream.close();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

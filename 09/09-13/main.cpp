// Код програми 9.13. Демонстрація механізму відображення вмісту файлу за допомогою функції get()

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
        cout << "Не вдається відкрити файл" << endl;
        return 1;
    }

    // Досягши кінця файлу потоковий об'єкт inStream прийме значення false
    while (inStream) {
        inStream.get(ch);
        if (inStream) cout << ch;
    }
    inStream.close();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

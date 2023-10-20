// Код програми 9.20. Демонстрація механізму відображення вмісту файлу із заданої позиції

#include <iostream>
#include <cstdlib>
#include <fstream>              // Для роботи з файлами

using namespace std;

int main(int argc, char* argv[]) {
    system("chcp 65001");
    char ch;
    if (argc != 3) {
        cout << "Застосування: iм'я_програми " << "<iм'я_файлу> <стapтова_позицiя>" << endl;
        return 1;
    }

    ifstream inStream(argv[1], ios::in | ios::binary);
    if (!inStream) {
        cout << "Не вдається вiдкрити файл" << endl;
        return 1;
    }

    inStream.seekg(atoi(argv[2]), ios::beg);

    while (inStream.get(ch)) cout << ch;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

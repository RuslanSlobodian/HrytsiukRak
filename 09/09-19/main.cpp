// Код програми 9.19. Демонстрація механізму використання функції seekp() для довільного доступу до вмісту файлу

#include <iostream>
#include <cstdlib>
#include <fstream>              // Для роботи з файлами

using namespace std;

int main(int argc, char* argv[]) {
    system("chcp 65001");
    if (argc != 3) {
        cout << "Застосування: iм'я_програми " << "<iм'я_файлу> <байт>" << endl;
        return 1;
    }

    fstream outStream(argv[1], ios::in | ios::out | ios::binary);
    if (!outStream) {

        cout << "Не вдається вiдкрити файл" << endl;
        return 1;
    }
    outStream.seekp(atoi(argv[2]), ios::beg);

    outStream.put('X');
    outStream.close();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Код програми 9.17. Демонстрація механізму застосування файлової системи для порівняння файлів

#include <iostream>
#include <cstdlib>
#include <fstream>              // Для роботи з файлами

using namespace std;

int main(int argc, char* argv[]) {
    system("chcp 65001");
    int i;
    unsigned char buf1[1024], buf2[1024];
    if (argc != 3) {
        cout << "Застосування: iм'я_програми <iм'я_файла1> " << "<iм'я_файла2>" << endl;
        return 1;
    }
    ifstream f1(argv[1], ios::in | ios::binary);
    if (!f1) {
        cout << "Не вдається вiдкрити перший файл" << endl;
        return 1;
    }
    ifstream f2(argv[2], ios::in | ios::binary);
    if (!f2) {
        cout << "Не вдається вiдкрити другий файл" << endl;
        return 1;
    }
    cout << "Порiвняння файлiв" << endl;
    do {
        f1.read((char*) buf1, sizeof buf1);
        f2.read((char*) buf2, sizeof buf2);
        if (f1.gcount() != f2.gcount()) {
            cout << "Файли мають рiзнi розмiри" << endl;
            f1.close();
            f2.close();
            //system("PAUSE");
            return EXIT_SUCCESS;
        }
        // Порівняння вмісту буферів
        for (i = 0; i < f1.gcount(); i++)
            if (buf1[i] != buf2[i]) {
                cout << "Файли рiзнi" << endl;
                f1.close();
                f2.close();
                //system("PAUSE");
                return EXIT_SUCCESS;
            }
    } while (!f1.eof() && !f2.eof());
    cout << "Файли однаковi" << endl;
    f1.close();
    f2.close();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

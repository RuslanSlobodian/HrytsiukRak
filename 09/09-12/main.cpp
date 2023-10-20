// Код програми 9.12. Демонстрація механізму зчитування даних з файлу

#include <iostream>
#include <cstdlib>
#include <fstream>              // Для роботи з файлами

using namespace std;

int main() {
    system("chcp 65001");
    char ch1, ch2;
    int c;
    float f;
    char str[80];

    ifstream inStream("test");
    if (!inStream) {
        cout << "Не вдається вiдкрити файл" << endl;
        return 1;
    }
    inStream >> c;
    inStream >> f;
    inStream >> ch1;
    inStream >> ch2;
    inStream >> str;

    cout << c << " " << f << " " << ch1 << ch2 << endl;
    cout << str;

    inStream.close();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

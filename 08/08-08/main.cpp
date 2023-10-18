// Код програми 8.8. Демонстрація механізму перехоплення винятків усіх типів

#include <iostream>
#include <cstdlib>

using namespace std;

void Xhandler(int test) {
    try {
        if (test == 0) throw test;  // Генерує int-винятки
        if (test == 1) throw 'a';   // Генерує char-винятки
        if (test == 2) throw 123.23;// Генерує double-винятки
    }
    catch (...) {                   // Перехоплення всіх винятків
        cout << "Перехоплення!" << endl;
    }
}

int main() {
    system("chcp 65001");
    cout << "Початок" << endl;
    Xhandler(0);
    Xhandler(1);
    Xhandler(2);

    cout << "Кiнець програми";

    //system("PAUSE");
    return EXIT_SUCCESS;
}

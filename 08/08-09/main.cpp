// Код програми 8.9. Демонстрація механізму використання настанови catch(...) для перехоплення винятків усіх інших типів

#include <iostream>
#include <cstdlib>

using namespace std;

void Xhandler(int test) {
    try {
        if (test == 0) throw test;      // Генерує int-винятки
        if (test == 1) throw 'a';       // Генерує char-винятки
        if (test == 2) throw 123.23;    // Генерує double-винятки
    }
    catch (int c) {             // Перехоплює int-винятки
        cout << "Перехоплення " << c << endl;
    }
    catch (...) {               // Перехоплює усі інші винятки
        cout << "Перехоплення-перехоплення!" << endl;
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

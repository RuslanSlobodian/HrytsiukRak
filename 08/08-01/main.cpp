// Код програми 8.1. Демонстрація механізму оброблення винятків

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    system("chcp 65001");
    cout << "Початок" << endl;
    try {                       // Початок try-блоку
        cout << "У try-блоцi" << endl;
        throw 99;               // Генерування помилки
        cout << "Цей код не буде виконано";
    }
    catch (int c) {             // Перехоплення помилки
        cout << "Значення перехопленого винятку дорiвнює: " << c << endl;
    }

    cout << "Кiнець програми";

    //system("PAUSE");
    return EXIT_SUCCESS;
}

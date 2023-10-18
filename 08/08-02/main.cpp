// Код програми 8.2. Демонстрація некоректної роботи коду програми

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    system("chcp 65001");
    cout << "Початок" << endl;
    try {                       // Початок try-блоку
        cout << "У try-блоцi" << endl;
        throw 99;               // генерування помилки
        cout << "Цей код не буде виконано";
    }
    catch (double c) {          // Перехоплення винятку типу int не відбудеться
        cout << "Значення перехопленого винятку дорiвнює: ";
        cout << c << endl;
    }
    cout << "Кiнець програми";

    //system("PAUSE");
    return EXIT_SUCCESS;
}

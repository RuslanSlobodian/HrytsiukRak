// Код програми 8.3. Демонстрація механізму генерування винятку функцією, що викликається з try-блоку

#include <iostream>
#include <cstdlib>

using namespace std;

void Xtest(int test) {
    cout << "У функцiї Xtest() значення test дорiвнює: " << test << endl;
    if (test) throw test;
}

int main() {
    system("chcp 65001");
    cout << "Початок" << endl;
    try {                       // Початок try-блоку
        cout << "У try-блоцi" << endl;
        Xtest(0);
        Xtest(1);
        Xtest(2);
    }
    catch (int c) {             // Перехоплення помилки
        cout << "Значення перехопленого винятку дорiвнює: ";
        cout << c << endl;
    }
    cout << "Кiнець програми";

    //system("PAUSE");
    return EXIT_SUCCESS;
}

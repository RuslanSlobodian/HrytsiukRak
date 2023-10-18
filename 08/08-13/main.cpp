// Код програми 8.13. Демонстрація механізму використання nothrow як старої версії оператора new

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    system("chcp 65001");
    int* p;
    p = new(nothrow) int[32];   // Використання nothrow-версії
    if (!p) {
        cout << "Пам'ять не виділена" << endl;
        return 1;
    }
    for (int i = 0; i < 32; i++) p[i] = i;
    for (int i = 0; i < 32; i++) cout << p[i] << " ";
    delete[] p;                 // Звільнення пам'яті

    //system("PAUSE");
    return EXIT_SUCCESS;
}

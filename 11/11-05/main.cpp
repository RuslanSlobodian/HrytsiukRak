// Код програми 11.5. Демонстрація механізму застосування вказівників на функції

#include <iostream>
#include <cstdlib>

using namespace std;

void hLine(int i) {
    for (; i; i--) cout << "-";
    cout << endl;
}

void vLine(int i) {
    for (; i; i--) cout << "|" << endl;
}

int main() {
    void (* p)(int i);

    p = vLine;                  // Вказівник на функцію vLine()

    (*p)(4);                    // Виклик функції vLine()

    p = hLine;                  // Вказівник на функцію hLine()

    (*p)(5);                    // Виклик функції hLine()

    //system("PAUSE");
    return EXIT_SUCCESS;
}

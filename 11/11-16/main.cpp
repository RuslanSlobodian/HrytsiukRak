// Код програми 11.16. Демонстрація механізму застосування специфікатора компонування функцій

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" void cFunction();

int main() {
    system("chcp 65001");
    cFunction();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Ця функція буде скомпонована як С-функція
void cFunction() {
    cout << "Ця функцiя скомпонована як С-функцiя" << endl;
}


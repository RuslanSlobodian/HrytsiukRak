// Код програми 13.2. Демонстрація неправильної роботи коду програми

#include <iostream>
#include <cstdlib>

using namespace std;

#define EVEN(a) a%2==0? 1 : 0

int main() {
    system("chcp 65001");
    if (EVEN(9 + 1))
        cout << "парне число";
    else
        cout << "непарне число ";

    //system("PAUSE");
    return EXIT_SUCCESS;
}

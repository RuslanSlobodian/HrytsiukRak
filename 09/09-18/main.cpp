// Код програми 9.18. Демонстрація механізму використання функції get()

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    system("chcp 65001");
    char str[80];
    cout << "Введiть iм'я: ";
    cin.get(str, 79);

    cout << str << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

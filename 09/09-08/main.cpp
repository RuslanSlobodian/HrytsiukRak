// Код програми 9.8. Демонстрація механізму використання маніпулятора ws,
// який пропускає провідні "пропускні" символи

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    char str[80];
    cin >> ws >> str;
    cout << str;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Код програми 9.10. Демонстрація механізму створення маніпулятора prompt()

#include <iostream>
#include <cstdlib>

using namespace std;

istream& prompt(istream& stream) {
    cin >> hex;
    cout << "Введiть число в шiстнадцятковому форматi: ";
    return stream;              // Повертає посилання на параметр stream в main
}

int main() {
    system("chcp 65001");
    int c;
    cin >> prompt >> c;
    cout << c;                  // Виведення числа в десятковому форматі

    //system("PAUSE");
    return EXIT_SUCCESS;
}

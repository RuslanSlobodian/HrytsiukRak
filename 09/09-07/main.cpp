// Код програми 9.7. Демонстрація механізму використання маніпулятора setiosflags()
// для встановлення опцій scientific і showpos

#include <iostream>
#include <cstdlib>
#include <iomanip>              // Використанняманіпуляторів введення-виведення

using namespace std;

int main() {
    // Відображення знаку "+" перед позитивним значенням числа
    cout << setiosflags(ios::showpos);

    // Відображення чисел у експоненціальному вигляді
    cout << setiosflags(ios::scientific);
    cout << 123 << " " << 123.23;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

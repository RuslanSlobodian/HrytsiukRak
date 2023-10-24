// Код програми 11.4. Демонстрація механізму внесення в глобальний простір імен декількох імен

#include <iostream>
#include <cstdlib>

// Отримуємо доступ до імен потоків cout і cin
using std::cout;
using std::cin;

int main() {
    double n;

    cout << "Введiть число: ";
    cin >> n;

    cout << "Ви ввели число ";
    cout << n;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

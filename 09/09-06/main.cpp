// Код програми 9.6. Демонстрація механізму використання маніпуляторів для керування
// процесом форматування даних, які виводяться

#include <iostream>
#include <cstdlib>
#include <iomanip>              // Використання маніпуляторів введення-виведення

using namespace std;

int main() {
    system("chcp 65001");
    cout << setprecision(2) << 1000.243 << endl;
    cout << setw(20) << "Всiм привiт! ";

    //system("PAUSE");
    return EXIT_SUCCESS;
}

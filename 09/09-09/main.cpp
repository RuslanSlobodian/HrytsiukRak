// Код програми 9.9. Демонстрація механізму створення маніпулятора setup()

#include <iostream>
#include <cstdlib>
#include <iomanip>              // Використання маніпуляторів введення-виведення

using namespace std;            // Використання стандартного простору імен

ostream& setup(ostream& stream) {
    stream.setf(ios::left);     // Вирівнювання лівим краєм

    // Встановлюєширину поля в 10 символів і задає як заповнювальний символ знак долара
    stream << setw(10) << setfill('$');

    return stream; // Повертає посилання на параметр stream
}

int main() {
    cout << 10 << " " << setup << 10;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

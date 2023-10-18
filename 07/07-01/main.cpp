// Код програми 7.1. Демонстрація механізму застосування шаблонної функції з одним узагальненим типом

#include <iostream>
#include <cstdlib>

using namespace std;

// Визначення шаблонної функції
template<typename aType>
void swapAB(aType &a, aType &b) {
    aType tmp;                  // Створення тимчасової змінної
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    system("chcp 65001");
    int i = 10, j = 20;
    double x = 10.1, y = 23.3;
    char a = 'x', b = 'z';
    cout << "Початковi значення i, j: " << i << " " << j << endl;
    cout << "Початковi значення x, y: " << x << " " << y << endl;
    cout << "Початковi значення a, b: " << a << " " << b << endl;
    swapAB(i, j);               // Перестановка цілих чисел
    swapAB(x, y);               // Перестановка чисел з плаваючою крапкою
    swapAB(a, b);               // Перестановка символів
    cout << "Пiсля перестановки i, j: " << i << " " << j << endl;
    cout << "Пiсля перестановки x, y: " << x << " " << y << endl;
    cout << "Пiсля перестановки a, b: " << a << " " << b << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

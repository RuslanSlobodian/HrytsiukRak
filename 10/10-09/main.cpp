// Код програми 10.9. Демонстрація механізму використання оператора const_cast

#include <iostream>
#include <cstdlib>

using namespace std;

void fun(const int* prt) {
    int* v;
    v = const_cast<int*> (prt); // Перевизначення const-атрибуту
    *v = 100;                   // Тепер об'єкт можна модифікувати
}

int main() {
    system("chcp 65001");
    int x = 99;
    cout << "Значення x до виклику функцiї fun(): " << x << endl;

    fun(&x);
    cout << "Значення x пiсля виклику функцiї fun(): " << x << endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}

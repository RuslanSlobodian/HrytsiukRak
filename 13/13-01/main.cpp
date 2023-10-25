// Код програми 13.1. Демонстрація механізму використання "функціональних" макровизначень

#include <iostream>
#include <cstdlib>

using namespace std;

#define MIN(a, b) (((a)<(b))? a: b)

int main() {
    system("chcp 65001");
    int x = 10, y = 20;
    cout << "Мiнiмум дорiвнює: " << MIN(x, y);

    //system("PAUSE");
    return EXIT_SUCCESS;
}

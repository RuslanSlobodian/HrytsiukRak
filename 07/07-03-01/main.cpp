// Код програми 7.3.1. Демонстрація механізму перевизначення специфікації шаблону функції

#include <iostream>
#include <cstdlib>

using namespace std;

// Перша версія шаблону function()
template<typename aType>
void function(aType a) {
    cout << "Виконується функцiя function(aType a)" << endl;
}

// Друга версія шаблону function()
template<typename aType, class bType>
void function(aType a, bType b) {
    cout << "Виконується функцiя function(aType a, bType b)" << endl;
}

int main() {
    system("chcp 65001");
    function(10);               // Викликається функція function(a)
    function(10, 20);           // Викликається функція function(a, b)
    //system("PAUSE");
    return EXIT_SUCCESS;
}

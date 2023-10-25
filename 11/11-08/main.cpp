// Код програми 11.8. Демонстрація механізму використання вказівників на дві перевизначені функції
// для виведення на екран відповідно пропусків і символів

#include <iostream>
#include <cstdlib>

using namespace std;

// Виведення на екран quantity пропусків
void space(int quantity) {
    for (; quantity; quantity--) cout << " ";
}

// Виведення на екран quantity символів, переданих в ch
void space(int quantity, char ch) {
    for (; quantity; quantity--) cout << ch;
}

int main() {
    // Створення вказівника на void-функцію з одним int-параметром
    void (* fp1)(int);

    // Створення вказівника на void-функцію з одним int-параметром і одним параметром типу char
    void (* fp2)(int, char);

    fp1 = space;                // Отримуємо адресу функції space(int)

    fp2 = space;                // Отримуємо адресу функції space(int, char)

    fp1(22);            // Виводимо 22 пропуски (цей виклик є аналогічним виклику (*fp1)(22))
    cout << "|" << endl;

    fp2(30, 'x');       // Виводимо 30 символів "x" (цей виклик є аналогічним до виклику (*fp2)(30, 'x')
    cout << "|" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

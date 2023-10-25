// Код програми 11.6. Демонстрація механізму використання бібліотечної функції qsort()
// для сортування елементів текстового масиву

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int comp(const void* a, const void* b) {
    return *(char*) a - *(char*) b;
}

int main() {
    system("chcp 65001");
    char str[] = "Вказівники на функцiї дають гнучкiсть";
    cout << "Вихідний рядок: " << str << endl;
    qsort(str, strlen(str), 1, comp);
    cout << "Вiдсортований рядок: " << str;

    cout << endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}

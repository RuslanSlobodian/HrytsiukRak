// Код програми 12.18. Демонстрація механізму використання функцій insert(), erase() і replace()

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    system("chcp 65001");
    string str1("Це простий тест.");
    string str2("ABCDEFG");
    cout << "Початковi рядки:" << endl;
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl << endl;

    // Демонструємо механізм використання функції insert()
    cout << "Вставляємо рядок str2 у рядок str1:" << endl;
    str1.insert(5, str2);
    cout << str1 << endl << endl;

    // Демонструємо механізм використання функції erase()
    cout << "Видаляємо 7 символiв з рядка str1:" << endl;
    str1.erase(5, 7);
    cout << str1 << endl << endl;

    // Демонструємо механізм використання функції replace()
    cout << "Замiнюємо 2 символи в str1 рядком str2:" << endl;
    str1.replace(5, 2, str2);
    cout << str1 << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

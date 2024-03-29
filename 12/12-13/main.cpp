// Код програми 12.13. Демонстрація механізму використання алгоритмів count і count_if

#include <iostream>
#include <cstdlib>
#include <vector>               // Для роботи з контейнерним класом "Вектор"
#include <algorithm>            // Для роботи з алгоритмами бібліотеки STL
#include <cctype>               // Для роботи з символьними аргументами

using namespace std;

// Це унарний предикат, який визначає, чи представляє цей символ голосний звук
// a б в г д е є ж з и і ї й к л м н о п р c т у ф x ц ч ш щ ю я ь

bool isVowel(char ch) {
    ch = tolower(ch);
    if (ch == 'а' || ch == 'е' || ch == 'є' || ch == 'и'
        || ch == 'і' || ch == 'ї' || ch == 'о' || ch == 'у'
        || ch == 'ю' || ch == 'я')
        return true;
    return false;
}

int main() {
    system("chcp 65001");
    char str[] = "STL-програмування -- це сила!";
    vector<char> vectorOfChars;
    unsigned int i;

    for (int i = 0; str[i]; i++)
        vectorOfChars.push_back(str[i]);
    cout << "Послiдовнiсть: ";

    for (int i = 0; i < vectorOfChars.size(); i++)
        cout << vectorOfChars[i];
    cout << endl;

    int n;
    char ch = 'н';
    n = count(vectorOfChars.begin(), vectorOfChars.end(), ch);
    cout << n << " символи '" << ch << "'" << endl;

    n = count_if(vectorOfChars.begin(), vectorOfChars.end(), [](char ch) { return isVowel(ch); });
    cout << n << " символiв представляють голоснi звуки" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

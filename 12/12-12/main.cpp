// Код програми 12.12. Демонстрація механізму використання відображення для створення словника

#include <iostream>
#include <cstdlib>
#include <map>                  // Для роботи з асоціативними контейнерами
#include <cstring>              // Для роботи з рядковими типами даних

using namespace std;

class Word {
    char charArray[20];
public:
    Word() { strcpy(charArray, ""); }

    Word(const char* s) { strcpy(charArray, s); }

    char* get() { return charArray; }
};

bool operator<(Word wordA, Word wordB) {
    return strcmp(wordA.get(), wordB.get()) < 0;
}

class Meaning {
    char charArray[80];
public:
    Meaning() { strcmp(charArray, ""); }

    Meaning(const char* str) { strcpy(charArray, str); }

    char* get() { return charArray; }
};

int main() {
    system("chcp 65001");
    map<Word, Meaning> dictionary;

    // Поміщаємо у відображення об'єкти класів Word і Meaning
    dictionary.insert(pair<Word, Meaning>(
            Word("дiм"), Meaning("Мiсце мешкання.")));
    dictionary.insert(pair<Word, Meaning>(
            Word("клавiатура"), Meaning("Пристрiй введення даних.")));
    dictionary.insert(pair<Word, Meaning>(
            Word("програмування"), Meaning("Процес розроблення програми.")));
    dictionary.insert(pair<Word, Meaning>(
            Word("STL"), Meaning("Standard Template Library")));

    // За заданим словом знаходимо його значення
    char charArray[80];
    cout << "Введiть слово: ";
    cin >> charArray;

    map<Word, Meaning>::iterator ptr;
    ptr = dictionary.find(Word(charArray));
    if (ptr != dictionary.end())
        cout << "Визначення: " << ptr->second.get();
    else
        cout << "Такого слова у словнику немає" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 12.12. Демонстрація механізму використання відображення для створення словника


#include <iostream>		// Для потокового введення-виведення
#include <cstdlib>		// Стандартна бібліотека С++
#include <map> 			// Для роботи з асоціативними контейнерами
#include <cstring> 		// Для роботи з рядковими типами даних

using namespace std; 			// Використання стандартного простору імен

class word {
    char str[20];
public:
    word() { strcpy(str, ""); }
    word(char *s) { strcpy(str, s); }
    char *get() { return str; }
};
bool operator<(word ObjA, word ObjB)
{
    return strcmp(ObjA.get(), ObjB.get()) < 0;
}

class meaning {
    char str[80];
public:
    meaning() { strcmp(str, ""); }
    meaning(char *s) { strcpy(str, s); }
    char *get() { return str; }
};

int main()
{
    map<word, meaning> dictionary;

    // Поміщаємо у відображення об'єкти класів word і meaning.
    dictionary.insert(pair<word, meaning>(
                          word("дiм"), meaning("Мiсце мешкання.")));

    dictionary.insert(pair<word, meaning>(
                          word("клавiатура"), meaning("Пристрiй введення даних.")));
    dictionary.insert(pair<word, meaning>(
                          word("програмування"), meaning("Процес розроблення програми.")));
    dictionary.insert(pair<word, meaning>(
                          word("STL"), meaning("Standard Template Library")));

    // За заданим словом знаходимо його значення.
    char str[80];
    cout << "Введiть слово: "; cin >> str;

    map<word, meaning>::iterator p;
    p = dictionary.find(word(str));
    if(p != dictionary.end())
        cout << "Визначення: " << p->second.get();
    else
        cout << "Такого слова у словнику немає" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

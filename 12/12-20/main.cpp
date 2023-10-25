// Код програми 12.20. Демонстрація механізму використання відображення string-об'єктів для створення словника

#include <iostream>
#include <cstdlib>
#include <map>
#include <string>

using namespace std;

int main() {
    system("chcp 65001");
    map<string, string> dictionary;

    dictionary.insert(pair<string, string>("дiм", "Мiсце мешкання."));
    dictionary.insert(pair<string, string>("клавiатура", "Пристрiй введення даних."));
    dictionary.insert(pair<string, string>("програмування", "Процес розроблення програми."));
    dictionary.insert(pair<string, string>("STL", "Standard Template Library."));

    string str;
    cout << "Введiть слово: ";
    cin >> str;

    map<string, string>::iterator ptr;

    ptr = dictionary.find(str);
    if (ptr != dictionary.end())
        cout << "Визначення: " << ptr->second << endl;
    else
        cout << "Такого слова у словнику немає." << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

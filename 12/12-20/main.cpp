//Код програми 12.20. Демонстрація механізму використання відображення string-об'єктів для створення словника


#include <iostream>		// Для потокового введення-виведення
#include <cstdlib>		// Стандартна бібліотека С++
#include <map> 			// Для роботи з асоціативними контейнерами
#include <string> 		// Для роботи з рядковими типами

using namespace std; 			// Використання стандартного простору імен

int main()
{
    map<string, string> dictionary;

    dictionary.insert(pair<string, string>("дiм", "Мiсце мешкання."));
    dictionary.insert(pair<string, string>("клавiатура", "Пристрiй введення даних."));
    dictionary.insert(pair<string, string>("програмування", "Процес розроблення програми."));
    dictionary.insert(pair<string, string>("STL", "Standard Template Library."));

    string s;
    cout << "Введiть слово: "; cin >> s;

    map<string, string>::iterator p;

    p = dictionary.find(s);
    if(p != dictionary.end())
        cout << "Визначення: " << p->second << endl;
    else
        cout << "Такого слова у словнику немає." << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

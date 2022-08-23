//Код програми 12.11. Демонстрація механізму використання простого відображення


#include <iostream>		// Для потокового введення-виведення
#include <cstdlib>		// Стандартна бібліотека С++
#include <map> 			// Для роботи з асоціативними контейнерами

using namespace std; 			// Використання стандартного простору імен

int main()
{
    map<char, int> h; // Створення порожнього відображення.
    // Поміщаємо пари у відображення.
    for(int i=0; i<10; i++) {
        h.insert(pair<char, int>('A'+i, i));
    }
    char ch;
    cout << "Введiть ключ: "; cin >> ch;

    map<char, int>::iterator p;
    // Знаходимо значення за заданим ключем.
    p = h.find(ch);
    if(p != h.end()) cout << p->second;
    else cout << "Такого ключа у вiдображеннi немає" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

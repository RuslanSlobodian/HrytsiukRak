// Код програми 12.7. Демонстрація механізму внесення елементів у список як з початку, так і з його кінця

#include <iostream>
#include <cstdlib>
#include <list> 			    // Для роботи зі списками

using namespace std;

int main()
{
    system("chcp 65001");
    list<char> listOfChars; 	// Створення порожнього списку
    list<char> listOfCharsReversed; // Створення порожнього списку

    // Поміщаємо значення у список
    for(int i=0; i<10; i++)
        listOfChars.push_back('A' + i);

    // Відображаємо початковий вміст списку
    cout << "Розмiр списку listOfChars = " << listOfChars.size() << endl;
    cout << "Початковий вмiст списку: ";
    list<char>::iterator ptr;

    // Видаляємо елементи із списку listOfChars і поміщаємо їх
    // у список listOfCharsReversed у зворотному порядку
    while(!listOfChars.empty()) {
        ptr = listOfChars.begin();
        cout << *ptr << " ";
        listOfCharsReversed.push_front(*ptr);
        listOfChars.pop_front();
    }
    cout << endl << endl;

    // Відображаємо реверсний вміст списку
    cout << "Розмiр списку listOfCharsReversed = ";
    cout << listOfCharsReversed.size() << endl;
    cout << "Реверсний вмiст списку: ";
    ptr = listOfCharsReversed.begin();
    while(ptr != listOfCharsReversed.end()) {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

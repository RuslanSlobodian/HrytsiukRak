//Код програми 12.

#include <iostream>		 	// Для потокового введення-виведення
#include <cstdlib>			// Стандартна бібліотека С++
#include <vector>			// Для роботи з контейнерним класом "Вектор"
#include <list> 			// Для роботи зі списками

using namespace std; 			// Використання стандартного простору імен

int main()
{
    list<char> lst1, lst2; 		// Створення двох порожніх списків

    // Створення двох списків з випадково вибраними цілими числами

    for(int i=0; i<10; i+=2) lst1.push_back('A'+i);
    for(int i=1; i<11; i+=2) lst2.push_back('A'+i);

    // Відображення початкового вмісту першого списку
    cout << "Вмiст списку lst1: ";
    list<char>::iterator p = lst1.begin();
    while(p != lst1.end()) {
        cout << *p;
        p++;
    }
    cout << endl << endl;

    // Відображення початкового вмісту другого списку
    cout << "Вмiст списку lst2: ";
    p = lst2.begin();
    while(p != lst2.end()) {
        cout << *p;
        p++;
    }
    cout << endl << endl;

    // Тепер об'єднуємо ці два списки.
    lst1.merge(lst2);
    if(lst2.empty()) cout << "Список lst2 тепер порожнiй" << endl;

    // Відображення об'єднаного вмісту першого списку
    cout << "Вмiст списку lst1 пiсля об'єднання:" << endl;
    p = lst1.begin();
    while(p != lst1.end()) {
        cout << *p << " ";
        p++;
    }
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

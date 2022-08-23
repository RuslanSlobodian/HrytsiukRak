//Код програми 12.8

#include <iostream>		 	// Для потокового введення-виведення
#include <cstdlib>			// Стандартна бібліотека С++
#include <vector>			// Для роботи з контейнерним класом "Вектор"
#include <list> 			// Для роботи зі списками

using namespace std; 			// Використання стандартного простору імен

int main()
{
    list<int> lst; 	// Створення порожнього списку
    // Створення списку випадково вибраних цілих чисел
    for(int i=0; i<10; i++) lst.push_back(rand());

    // Відображення початкового вмісту списку

    cout << "Початковий вмiст списку:" << endl;
    list<int>::iterator p = lst.begin();
    while(p != lst.end()) {
        cout << *p << " ";
        p++;
    }
    cout << endl << endl;

    // Сортування списку.
    lst.sort();

    // Відображення відсортованого вмісту списку
    cout << "Вiдсортований вмiст списку:" << endl;
    p = lst.begin();
    while(p != lst.end()) {
        cout << *p << " ";
        p++;
    }
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

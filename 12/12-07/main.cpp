//Код програми 12.7. Демонстрація механізму внесення елементів у список як з початку, так і з його кінця

#include <iostream>		 	// Для потокового введення-виведення
#include <cstdlib>			// Стандартна бібліотека С++
#include <vector>			// Для роботи з контейнерним класом "Вектор"
#include <list> 			// Для роботи зі списками

using namespace std; 			// Використання стандартного простору імен

int main()
{
    list<char> lst; 		// Створення порожнього списку
    list<char> revlst; 		// Створення порожнього списку

    // Поміщаємо значення у список
    for(int i=0; i<10; i++) lst.push_back('A'+i);

    // Відображаємо початковий вміст списку
    cout << "Розмiр списку lst = " << lst.size() << endl;
    cout << "Початковий вмiст списку: ";
    list<char>::iterator p;

    /* Видаляємо елементи із списку lst і поміщаємо їх
    у список revlst у зворотному порядку. */
    while(!lst.empty()) {
        p = lst.begin();
        cout << *p << " ";
        revlst.push_front(*p);
        lst.pop_front();
    }
    cout << endl << endl;

    // Відображаємо реверсний вміст списку
    cout << "Розмiр списку revlst = ";
    cout << revlst.size() << endl;
    cout << "Реверсний вмiст списку: ";
    p = revlst.begin();
    while(p != revlst.end()) {
        cout << *p << " ";
        p++;
    }
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

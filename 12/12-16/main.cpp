//Код програми 12.16. Демонстрація механізму використання алгоритму transform()

#include <iostream>		 // Для потокового введення-виведення
#include <cstdlib>		// Стандартна бібліотека С++
#include <list> 		// Для роботи зі списками
#include <algorithm> 	// Для роботи з алгоритмами бібліотеки STL


using namespace std; 			// Використання стандартного простору імен

// Проста функція перетворення.
int xform(int i) {
    return i * i; // Квадрат початкового значення
}

int main()
{
    list<int> xList;
    int i;
    // Поміщаємо значення у список.
    for(int i=0; i<10; i++) xList.push_back(i);
    cout << "Початковий список xList: ";
    list<int>::iterator p = xList.begin();
    while(p != xList.end()) {
        cout << *p << " ";
        p++;
    }
    cout << endl;
    // Перетворення списку xList.
    p = transform(xList.begin(), xList.end(), xList.begin(), xform);

    cout << "Перетворений список xList: ";
    p = xList.begin();
    while(p != xList.end()) {
        cout << *p << " ";
        p++;
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

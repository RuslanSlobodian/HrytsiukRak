//Код програми 12.2. Демонстрація механізму доступу до елементів вектора за допомогою ітератора

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <vector>				// Для роботи з контейнерним класом "Вектор"

using namespace std; 			// Використання стандартного простору імен

int main()
{
    vector<char> vek; 	// Побудова вектора нульової довжини

    // Поміщаємо значення у вектор.
    for(int i=0; i<10; i++) vek.push_back('A' + i);

    // Отримуємо доступ до вмісту вектора за допомогою індексу.
    for(int i=0; i<10; i++) cout << vek[i] << " ";
    cout << endl;

    // Отримуємо доступ до вмісту вектора за допомогою ітератора.
    vector<char>::iterator p = vek.begin();
    while(p != vek.end()) {
        cout << *p << " ";
        p++;
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

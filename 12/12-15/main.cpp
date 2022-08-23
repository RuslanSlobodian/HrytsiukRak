//Код програми 12.15. Демонстрація механізму використання алгоритму reverse

#include <iostream>		 // Для потокового введення-виведення
#include <cstdlib>		// Стандартна бібліотека С++
#include <vector>		// Для роботи з контейнерним класом "Вектор"
#include <algorithm> 	// Для роботи з алгоритмами бібліотеки STL

using namespace std; 			// Використання стандартного простору імен

int main()
{
    vector<int> vek;
    unsigned int i;

    for(int i=0; i<10; i++) vek.push_back(i);

    cout << "Початкова послiдовнiсть: ";
    for(int i=0; i<vek.size(); i++) cout << vek[i] << " ";
    cout << endl;

    reverse(vek. begin(), vek.end());

    cout << "Реверсована послiдовнiсть: ";
    for(int i=0; i<vek.size(); i++) cout << vek[i] << " ";

    //system("PAUSE");
    return EXIT_SUCCESS;
}

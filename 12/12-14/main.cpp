//Код програми 12.14. Демонстрація механізму використання алгоритмів remove_copy і replace_copy

#include <iostream>		// Для потокового введення-виведення
#include <cstdlib>		// Стандартна бібліотека С++
#include <vector> 		// Для роботи з контейнерним класом "Вектор"
#include <algorithm> 	// Для роботи з алгоритмами бібліотеки STL


using namespace std; 			// Використання стандартного простору імен

int main()
{
    char str[] = "Це дуже простий тест.";
    vector<char> vek, vek2(30);

    for(int i=0; str[i]; i++) vek.push_back(str[i]);

    // **** Демонстрація алгоритму remove_copy ****

    cout << "Вхiдна послiдовнiсть: ";
    for(int i=0; i<vek.size(); i++) cout << vek[i];
    cout << endl;

    // Видаляємо всі букви 'е'.
    remove_copy(vek.begin(), vek.end(), vek2.begin(), 'т');

    cout << "Пiсля видалення букв 'т': ";
    for(int i=0; vek2[i]; i++) cout << vek2[i];
    cout << endl << endl;

    // **** Демонстрація алгоритму replace_copy ****

    cout << "Вхiдна послiдовнiсть: ";
    for(int i=0; i<vek.size(); i++) cout << vek[i];
    cout << endl;

    // Замінюємо букви 'е' буквами 'Х'.
    replace_copy(vek.begin(), vek.end(), vek2.begin(), 'е', 'X');

    cout << "Пiсля замiни букв 'е' буквами 'X': ";
    for(int i=0; vek2[i]; i++) cout << vek2[i];
    cout << endl << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

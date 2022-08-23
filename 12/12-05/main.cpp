//Код програми 12.5. Демонстрація механізму використання ітераторів для вставлення елементів одного вектора у інший

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <vector>				// Для роботи з контейнерним класом "Вектор"

using namespace std; 			// Використання стандартного простору імен

int main()
{
    vector<char> vek, vek2; // Побудова векторів нульової довжини

    // Поміщаємо значення у вектор.
    for(int i=0; i<10; i++) vek.push_back('A' + i);

    // Відображаємо початковий вміст вектора.
    cout << "Початковий вмiст вектора:" << endl;
    for(int i=0; i<vek.size(); i++) cout << vek[i] << " ";
    cout << endl << endl;

    // Ініціалізуємо другий вектор.
    char str[] = "-STL -- це сила!-";
    for(int i=0; str[i]; i++) vek2.push_back(str[i]);

    /* Отримуємо ітератори для середини вектора vek,
    а також початку і кінця вектора vek2. */
    vector<char>::iterator p = vek.begin()+5;
    vector<char>::iterator p2start = vek2.begin();
    vector<char>::iterator p2end = vek2.end();

    // Вставляємо вектор vek2 у вектор vek.
    vek.insert(p, p2start, p2end);

    // Відображаємо результат вставлення.
    cout << "Вмiст вектора vek пiсля вставлення: " << endl;
    for(int i=0; i<vek.size(); i++) cout << vek[i] << " ";
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

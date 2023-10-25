//Код програми 12.3. Демонстрація механізму вставлення елементів у вектор і видалення їх з нього

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <vector>				// Для роботи з контейнерним класом "Вектор"

using namespace std; 			// Використання стандартного простору імен

int main()
{
    vector<char> vek; // Побудова вектора нульової довжини

    // Поміщаємо значення у вектор.
    for(int i=0; i<10; i++) vek.push_back('A' + i);

    // Відображаємо початковий вміст вектора.
    cout << "Розмiр = " << vek.size() << endl;
    cout << "Початковий вмiст вектора:" << endl;
    for(int i=0; i<vek.size(); i++) cout << vek[i] << " ";
    cout << endl;

    // Отримуємо доступ до вмісту вектора за допомогою ітератора.
    vector<char>::iterator p = vek.begin();
    p += 2; // Вказівник на 3-й елемент вектора

    // Вставляємо 10 символів 'x' у вектор vek.
    vek.insert(p, 10, 'x');
    // Відображаємо вміст вектора після вставлення символів.
    cout << "Розмiр вектора пiсля вставлення = " << vek.size() << endl;
    cout << "Вмiст вектора пiсля вставлення:" << endl;
    for(int i=0; i<vek.size(); i++) cout << vek[i] << " ";
    cout << endl;

    // Видалення вміщених елементів.
    p = vek.begin();
    p += 2; // Вказівник на 3-й елемент вектора
    vek.erase(p, p+10); // Видаляємо 10 елементів підряд.
    // Відображаємо вміст вектора після видалення символів.
    cout << "Розмiр вектора пiсля видалення символiв = " << vek.size() << endl;
    cout << "Вмiст вектора пiсля видалення символiв:" << endl;
    for(int i=0; i<vek.size(); i++) cout << vek[i] << " ";
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

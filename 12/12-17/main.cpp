//Код програми 12.17. Демонстрація механізму використання класу String для оброблення рядків


#include <iostream>		 // Для потокового введення-виведення
#include <cstdlib>		// Стандартна бібліотека С++
#include <string> 		// Для роботи з рядковими типами

using namespace std; 			// Використання стандартного простору імен

int main()
{
    string str1("Клас string дає змогу ефективно ");
    string str2("обробляти рядки.");

    string str3;

    // Присвоєння string-об'єкта
    str3 = str1;
    cout << str1 << endl << str3 << endl;

    // Конкатенація двох string-об'єктів.
    str3 = str1 + str2;
    cout << str3 << endl;

    // Порівняння string-об'єктів.
    if(str3 > str1) cout << "str3 > str1" << endl;
    if(str3 == str1 + str2)
        cout << "str3 == str1 + str2" << endl;

    // Об'єкту класу string можна також присвоїти звичайний рядок.
    str1 = "Це рядок, який завершується нульовим символом" ;
    cout << str1 << endl;

    // Створення string-об'єкта за допомогою іншого string-об'єкта.
    string str4(str1);
    cout << str4;

    // Введення рядка.
    cout << "Введiть рядок: "; cin >> str4;
    cout << str4;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

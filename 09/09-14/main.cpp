//Код програми 9.14. Демонстрація механізму використання функції put() для запису рядка уфайл

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <fstream>			// Для роботи з файлами

using namespace std; 			// Використання стандартного простору імен

int main()
{
    char *p = "Всiм привiт!";

    ofstream out("test", ios::out | ios::binary);

    if(!out) {
        cout << "Не вдається вiдкрити файл" << endl;
        return 1;
    }
    while(*p) out.put(*p++);

    out.close();
    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 9.11. Демонстрація механізму запису даних у файл

#include <iostream>		 	// Для потокового введення-виведення
#include <cstdlib>			// Стандартна бібліотека С++
#include <fstream>			// Для роботи з файлами

using namespace std; 			// Використання стандартного простору імен

int main()
{
    ofstream out("test");
    if(!out) {
        cout << "Не вдається відкрити файл" << endl;
        return 1;
    }
    out << 10 << " " << 123.23 << endl;
    out << "Це короткий текстовий файл.";

    out.close();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

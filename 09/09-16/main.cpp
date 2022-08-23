//Код програми 9.16. Демонстрація механізму виявлення кінця файлу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <fstream>			// Для роботи з файлами

using namespace std; 			// Використання стандартного простору імен

int main(int argc, char *argv[])
{
    char ch;
    if(argc != 2) {
        cout << "Застосування: iм'я_програми <iм'я_файлу>" << endl;
        return 1;
    }
    ifstream in(argv[1], ios::in | ios::binary);
    if(!in) {
        cout << "Не вдається вiдкрити файл" << endl;
        return 1;
    }
    while(!in.eof()) { // Використання функції eof()
        in.get(ch);
        if(!in.eof()) cout << ch;
    }
    in.close();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

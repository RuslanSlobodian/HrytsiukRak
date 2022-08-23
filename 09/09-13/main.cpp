//Код програми 9.

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <fstream>		 	// Для роботи з файлами

using namespace std; 			// Використання стандартного простору імен

int main(int argc, char *argv[])
{
    char ch;

    if(argc !=2) {
        cout << "Застосування: iм'я_програми <iм'я_файлу>" << endl;
        return 1;
    }
    ifstream in(argv[1], ios::in | ios::binary);
    if(!in) {
        cout << "Не вдається відкрити файл" << endl;
        return 1;
    }
    while(in) { // Досягши кінцяфайлу потоковий об'єктin прийме значення false.
        in.get(ch);
        if(in) cout << ch;
    }
    in.close();

    system("PAUSE");
    return EXIT_SUCCESS;
}

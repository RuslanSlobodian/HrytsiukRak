//Код програми 9.20. Демонстрація механізму відображення вмісту файлу із заданої позиції

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <fstream>			// Для роботи з файлами

using namespace std; 			// Використання стандартного простору імен

int main(int argc, char *argv[])
{
    char ch;
    if(argc !=3) {
        cout << "Застосування: iм'я_програми " << "<iм'я_файлу> <стapтова_позицiя>" << endl;
        return 1;
    }

    ifstream in(argv[1], ios::in | ios::binary);
    if(!in) {
        cout << "Не вдається вiдкрити файл" << endl;
        return 1;
    }

    in.seekg(atoi(argv[2]), ios::beg);

    while(in.get(ch)) cout << ch;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 9.19. Демонстрація механізму використання функції seekp() для довільного доступу до вмісту файлу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <fstream>			// Для роботи з файлами

using namespace std; 			// Використання стандартного простору імен

int main(int argc, char *argv[])
{
    if(argc !=3) {
        cout << "Застосування: iм'я_програми " << "<iм'я_файлу> <байт>" << 	endl;
        return 1;
    }

    fstream out(argv[1], ios::in | ios::out | ios::binary);
    if(!out) {

        cout << "Не вдається вiдкрити файл" << endl;
        return 1;
    }
    out.seekp(atoi(argv[2]), ios::beg);

    out.put('X');
    out.close();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

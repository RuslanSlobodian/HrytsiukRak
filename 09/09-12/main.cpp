//Код програми 9.12. Демонстраціямеханізму зчитування даних зфайлу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <fstream>			// Для роботи з файлами

using namespace std; 			// Використання стандартного простору імен

int main()
{
    char ch1, ch2;
    int c;
    float f;
    char str[80];

    ifstream in("test");
    if(!in) {
        cout << "Не вдається вiдкрити файл" << endl;
        return 1;
    }
    in >> c;
    in >> f;
    in >> ch1;
    in >> ch2;
    in >> str;

    cout << c << " " << f << " " << ch1 << ch2 << endl;
    cout << str;

    in.close();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

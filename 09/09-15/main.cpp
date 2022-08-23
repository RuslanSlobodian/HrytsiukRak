//Код програми 9.15. Демонстрація механізму використання функцій read() і write()

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <fstream>			// Для роботи з файлами

using namespace std; 			// Використання стандартного простору імен

int main()
{
    int n[5] = {1, 2, 3, 4, 5};
    register int i;

    ofstream out("test", ios::out | ios::binary);
    if(!out) {
        cout << "Не вдається вiдкрити файл" << endl;
        return 1;
    }
    out.write((char *) &n, sizeof n);
    out.close();

    for(i=0; i<5; i++) n[i] = 0; // Очищує масив

    ifstream in("test", ios::in | ios::binary);
    if(!in) {
        cout << "Не вдається вiдкрити файл" << endl;
        return 1;
    }
    in.read((char *) &n, sizeof n);
    for(i=0; i<5; i++) // Відображаємо значення, зчитанізфайлу.
        cout << n[i] << " ";
    in.close();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

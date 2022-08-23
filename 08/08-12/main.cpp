//Код програми 8.12. Демонстрація механізму оброблення винятків, згенерованих оператором new

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

int main()
{
    int *p;
    try {
        p = new int[32]; // Запит на виділення області пам'яті
        // для 32-елементного int-масиву
    }
    catch(bad_alloc xa) {
        cout << "Пам'ять не видiлена" << endl;
        return 1;
    }
    for(int i=0; i<32; i++) p[i] = i;
    for(int i=0; i<32; i++) cout << p[i] << " ";
    delete [] p; // Звільнення пам'яті

    //system("PAUSE");
    return EXIT_SUCCESS;
}

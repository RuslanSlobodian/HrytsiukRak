//Код програми 8.13. Демонстрація механізму використання nothrow як староїверсії оператора new

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

int main()
{
    int *p;
    p = new(nothrow) int[32]; 		// Використання nothrow-версії
    if(!p) {
        cout << "Пам'ять не виділена" << endl;
        return 1;
    }
    for(int i=0; i<32; i++) p[i] = i;
    for(int i=0; i<32; i++) cout << p[i] << " ";
    delete [] p; // Звільнення пам'яті

    //system("PAUSE");
    return EXIT_SUCCESS;
}

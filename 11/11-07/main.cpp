//Код програми 11.7. Демонстрація механізму використання бібліотечної функції
//qsort() для сортування елементів цілочисельного масиву


#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

int Comp(const void *a, const void *b)
{
    return * (char *) a – * (char *) b;
}


int main()
{
    int num[] = {10, 4, 3, 6, 5, 7, 8};

    qsort(num, 7, sizeof(int), Comp);

    for(int i=0; i<7; i++)
        cout << num[i]<< " ";
    cout << endl;


    //system("PAUSE");
    return EXIT_SUCCESS;
}

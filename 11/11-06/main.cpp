//Код програми 11.6. Демонстрація механізму використання бібліотечної функції qsort() для сортування елементів текстового масиву

#include <iostream>		 	// Для потокового введення-виведення
#include <cstdlib>			// Стандартна бібліотека С++
#include <cstring>    		// Для роботи з рядковими типами даних


using namespace std; 			// Використання стандартного простору імен

int Comp(const void *a, const void *b)
{
    return * (char *) a – * (char *) b;
}

int main()
{
    char str[] = "Покажчики на функцiї дають гнучкiсть.";

    qsort(str, strlen(str), 1, Comp);
    cout << "Вiдсортований рядок: " << str;
    cout << endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 2.13. Демонстрація механізму ініціалізації масиву об'єктів параметризованим конструктором з декількома аргументами

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class myClass {		 // Оголошення класового типу
    int a, b;
public:
    myClass(int c, int d) { a = c; b = d; }
    int PutA() { return a; }
    int PutB() { return b; }
};

int main()
{
    myClass array[4][2] = {
        myClass(1, 2), myClass(3, 4),
        myClass(5, 6), myClass(7, 8),
        myClass(9, 10), myClass(11, 12),
        myClass(13, 14), myClass(15, 16)
    };
    for(int i=0; i<4; i++)
        for(int j=0; j<2; j++) {
            cout << "array[" << i << "," << j << "] ==> a= ";
            cout << array[i][j].PutA() << "; b= ";
            cout << array[i][j].PutB() << endl;
        }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

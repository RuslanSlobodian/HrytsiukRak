//Код програми 2.12. Демонстрація механізму ініціалізації масиву об'єктів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class myClass {		 // Оголошення класового типу
    int a;
public:
    myClass(int b) { a = b; }
    double Put() { return a; }
};

int main()
{
    myClass array[4] = { -1, -2, -3, -4 };
    for(int i=0; i<4; i++)
        cout << "array[" << i << "]= " << array[i].Put() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

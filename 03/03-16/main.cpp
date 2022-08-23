//Код програми 3.16. Демонстрація механізму застосування ключового слова this

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class myClass { // Оголошення класового типу
    int c;
public:
    void Get(int n) { this->c = n; } // те саме, що c = n
    int Put() { return this->c; } // те саме, що return c
};
int main()
{
    myClass Obj; // Створення об'єкта класу
    Obj.Get(100);
    cout << "c= " << Obj.Put() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

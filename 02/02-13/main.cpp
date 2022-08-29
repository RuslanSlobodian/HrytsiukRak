// Код програми 2.13. Демонстрація механізму ініціалізації масиву об'єктів параметризованим конструктором з декількома аргументами

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
    int a;
    int b;
public:
    MyClass(int c, int d) { a = c; b = d; }
    int getA() { return a; }
    int getB() { return b; }
};

int main() {
    MyClass array[4][2] = {
        {MyClass(1, 2), MyClass(3, 4)},
        {MyClass(5, 6), MyClass(7, 8)},
        {MyClass(9, 10), MyClass(11, 12)},
        {MyClass(13, 14), MyClass(15, 16)}
    };
    for(int i = 0; i < 4; i++)
        for(int j=0; j<2; j++) {
            cout << "array[" << i << "," << j << "] ==> a = ";
            cout << array[i][j].getA() << "; b = ";
            cout << array[i][j].getB() << endl;
        }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 11.13. Демонстрація механізму використання неявногоперетворення конструктора

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class MyClass { 		     // Оголошення класового типу
    int n;
public:
    MyClass(int c) { n = c; }
    int getData() { return n; }
};
int main()
{
    MyClass objectB(10);

    cout << objectB.getData() << endl; // Відображає 10
    // Тепер використовуємо неявне перетворення для присвоєння 			нового значення.
    objectB = 1000;
    cout << objectB.getData() << endl; // Відображає 1000

    //system("PAUSE");
    return EXIT_SUCCESS;
}

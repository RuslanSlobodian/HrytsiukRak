//Код програми 11.13. Демонстрація механізму використання неявногоперетворення конструктора

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class myClass { 		     // Оголошення класового типу
    int n;
public:
    myClass(int c) { n = c; }
    int Put() { return n; }
};
int main()
{
    myClass Obj(10);

    cout << Obj.Put() << endl; // Відображає 10
    // Тепер використовуємо неявне перетворення для присвоєння 			нового значення.
    Obj = 1000;
    cout << Obj.Put() << endl; // Відображає 1000

    //system("PAUSE");
    return EXIT_SUCCESS;
}

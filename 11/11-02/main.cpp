//Код програми 11.2. Демонстрація механізму використання настанови using для виконання розрахунку у зворотному порядку

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

namespace CounterNameSpace
{
int upperbound;
int lowerbound;

class counter {
    int count;
public:
    counter(int n) {
        if(n <= upperbound) count = n;
        else count = upperbound;
    }

    void Reset(int n) {
        if(n <= upperbound) count = n;
    }

    int Run() {
        if(count > lowerbound) return count--;
        else return lowerbound;
    }
};
}

int main()
{
    // Використовується тільки член upperbound з
    // простору імен CounterNameSpace.
    using CounterNameSpace::upperbound;

    // Тепер для встановлення значення змінній upperbound
    // не потрібно вказувати простір імен.
    upperbound = 100;

    // Але під час звернення до змінної lowerbound і до інших
    // об'єктів, як і раніше, необхідно вказувати простір імен.
    CounterNameSpace::lowerbound = 0;
    CounterNameSpace::counter ObjA (10);
    int c;

    cout << "Розрахунок у зворотному порядку для об'єкта ObjA" << endl;
    do {
        c = ObjA.Run();
        cout << c << " ";
    } while(c > CounterNameSpace::lowerbound);
    cout << endl;

    // Тепер використовуємо весь простір імен CounterNameSpace.
    using namespace CounterNameSpace;

    counter ObjB(20);

    cout << "Розрахунок у зворотному порядку для об'єкта ObjB" << endl;
    do {
        c = ObjB.Run();
        cout << c << " ";
    } while(c > lowerbound);
    cout << endl;

    ObjB.Reset(100);
    lowerbound = 80;
    cout << "Розрахунок у зворотному порядку для об'єкта ObjB" << endl;
    do {
        c = ObjB.Run();
        cout << c << " ";
    } while(c > lowerbound);
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 11.1. Демонстрація механізму використання простору імен CounterNameSpace для розрахунку у зворотному порядку

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

// Приклад використання namespace-настанови
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
    CounterNameSpace::upperbound = 100;
    CounterNameSpace::lowerbound = 0;
    CounterNameSpace::counter ObjA(10);
    CounterNameSpace::counter ObjB(20);

    int c;

    cout << "Розрахунок у зворотному порядку для об'єкта ObjA" << 		endl;
    do {
        c = ObjA.Run();
        cout << c << " ";
    } while(c > CounterNameSpace::lowerbound);
    cout << endl;
    cout << "Розрахунок у зворотному порядку для об'єкта ObjB" << 		endl;
    do {
        c = ObjB.Run();
        cout << c << " ";
    } while(c > CounterNameSpace::lowerbound);
    cout << endl;

    ObjB.Reset(100);
    CounterNameSpace::lowerbound = 80;

    cout << "Розрахунок у зворотному порядку для об'єкта ObjB" << 		endl;
    do {
        c = ObjB.Run();
        cout << c << " ";
    } while(c > CounterNameSpace::lowerbound);
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

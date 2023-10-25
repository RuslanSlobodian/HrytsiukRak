// Код програми 11.1. Демонстрація механізму використання простору імен CounterNameSpace для розрахунку у зворотному порядку

#include <iostream>
#include <cstdlib>

using namespace std;

// Приклад використання namespace-настанови
namespace CounterNameSpace {
    int upperBound;
    int lowerBound;

    class Counter {
        int count;
    public:
        Counter(int number) {
            if (number <= upperBound)
                count = number;
            else
                count = upperBound;
        }

        void reset(int number) {
            if (number <= upperBound)
                count = number;
        }

        int run() {
            if (count > lowerBound)
                return count--;
            else
                return lowerBound;
        }
    };
}

int main() {
    system("chcp 65001");
    CounterNameSpace::upperBound = 100;
    CounterNameSpace::lowerBound = 0;
    CounterNameSpace::Counter counterA(10);
    CounterNameSpace::Counter counterB(20);

    int temp;

    cout << "Розрахунок у зворотному порядку для об'єкта counterA" << endl;
    do {
        temp = counterA.run();
        cout << temp << " ";
    } while (temp > CounterNameSpace::lowerBound);
    cout << endl;
    cout << "Розрахунок у зворотному порядку для об'єкта counterB" << endl;
    do {
        temp = counterB.run();
        cout << temp << " ";
    } while (temp > CounterNameSpace::lowerBound);
    cout << endl;

    counterB.reset(100);
    CounterNameSpace::lowerBound = 80;

    cout << "Розрахунок у зворотному порядку для об'єкта counterB" << endl;
    do {
        temp = counterB.run();
        cout << temp << " ";
    } while (temp > CounterNameSpace::lowerBound);
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

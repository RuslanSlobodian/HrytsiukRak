// Код програми 11.2. Демонстрація механізму використання настанови using для виконання розрахунку у зворотному порядку

#include <iostream>
#include <cstdlib>

using namespace std;

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

        void reset(int n) {
            if (n <= upperBound)
                count = n;
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
    // Використовується тільки член upperBound з простору імен CounterNameSpace
    using CounterNameSpace::upperBound;

    // Тепер для встановлення значення змінній upperBound не потрібно вказувати простір імен
    upperBound = 100;

    // Але під час звернення до змінної lowerBound і до інших
    // об'єктів, як і раніше, необхідно вказувати простір імен
    CounterNameSpace::lowerBound = 0;
    CounterNameSpace::Counter counterA(10);
    int temp;

    cout << "Розрахунок у зворотному порядку для об'єкта counterA" << endl;
    do {
        temp = counterA.run();
        cout << temp << " ";
    } while (temp > CounterNameSpace::lowerBound);
    cout << endl;

    // Тепер використовуємо весь простір імен CounterNameSpace
    using namespace CounterNameSpace;

    Counter counterB(20);

    cout << "Розрахунок у зворотному порядку для об'єкта counterB" << endl;
    do {
        temp = counterB.run();
        cout << temp << " ";
    } while (temp > lowerBound);
    cout << endl;

    counterB.reset(100);
    lowerBound = 80;
    cout << "Розрахунок у зворотному порядку для об'єкта counterB" << endl;
    do {
        temp = counterB.run();
        cout << temp << " ";
    } while (temp > lowerBound);
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

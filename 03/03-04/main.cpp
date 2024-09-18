// Код програми 3.4. Демонстрація механізму використання перевизначених конструкторів

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++
#include <ctime>                // Для використання системного часу і дати

using namespace std;            // Використання стандартного простору імен

class TimerClass {              // Оголошення класового типу
    int s;
public:
    // Задавання секунд у вигляді символьного рядка
    TimerClass(const char* str) {
        s = atoi(str);
    }

    // Задавання секунд у вигляді цілого числа
    TimerClass(int seconds) {
        s = seconds;
    }

    // Час, який задається в хвилинах і секундах
    TimerClass(int minutes, int seconds) {
        s = minutes * 60 + seconds;
    }

    // Час, який задається в годинах, хвилинах і секундах
    TimerClass(int hours, int minutes, int seconds) {
        s = 60 * (hours * 60 + minutes) + seconds;
    }

    void run();                 // Запуск таймера відліку часу
};

void TimerClass::run() {
    clock_t t1 = clock();
    while ((clock() / CLOCKS_PER_SEC - t1 / CLOCKS_PER_SEC) < s);
    cout << "\a";               // Подання звукового сигналу
}

int main() {
    TimerClass objectA("10");
    objectA.run();              // Відлік 10 секунд

    TimerClass objectB(20);
    objectB.run();              // Відлік 20 секунд

    TimerClass objectC(1, 10);
    objectC.run();              // Відлік 1 хвилини і 10 секунд

    TimerClass objectD(0, 2, 8);
    objectD.run();              // відлік 0 годин 2 хвилини і 8 секунд

    //system("PAUSE");
    return EXIT_SUCCESS;
}

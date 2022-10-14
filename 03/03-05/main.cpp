// Код програми 3.5. Демонстрація механізму динамічної ініціалізації конструктора

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <ctime> 				// Для використання системного часу і дати

using namespace std; 			// Використання стандартного простору імен

class TimerClass {              // Оголошення класового типу
    int s;
public:
    // Задавання секунд у вигляді символьного рядка
    TimerClass(char* str) {
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
        s = 60 * ( hours * 60 + minutes) + seconds;
    }
    void run();                 // Запуск таймера відліку часу
};

void TimerClass::run() {
    clock_t t1 = clock();
    while((clock()/CLOCKS_PER_SEC - t1/CLOCKS_PER_SEC)< s);
    cout << "\a";               // Подання звукового сигналу
}

int main() {
    TimerClass objectA(10);     // Створення об'єкта класу
    objectA.run();

    char str[80];
    cout << "Введiть кiлькiсть секунд: ";
    cin >> str;
    TimerClass objectB(str);    // Динамічна ініціалізація конструктора
    objectB.run();

    int minutes;
    int seconds;
    cout << "Введiть хвилини i секунди: ";
    cin >> minutes >> seconds;

    // Динамічна ініціалізація конструктора
    TimerClass objectC(minutes, seconds);
    objectC.run();

    int hours;
    cout << "Введiть години, хвилини i секунди: ";
    cin >> hours >> minutes >> seconds;

    // Динамічна ініціалізація конструктора
    TimerClass objectD(hours, minutes, seconds);
    objectD.run();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

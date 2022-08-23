//Код програми 3.5. Демонстрація механізму динамічної ініціалізації конструктора

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <ctime> 				// Для використання системного часу і дати

using namespace std; 			// Використання стандартного простору імен

class timerClass { // Оголошення класового типу
    int s;
public:
    // Задавання секунд у вигляді рядка
    timerClass(char *t) { s = atoi(t); }
    // Задавання секунд у вигляді цілого числа
    timerClass(int t) { s = t; }
    // Час, який задається в хвилинах і секундах
    timerClass(int xv, int sec) { s = xv*60 + sec; }
    // Час, який задається в годинах, хвилинах і секундах
    timerClass(int hod, int xv, int sec) { s = 60*(hod*60 + xv) + sec; }
    void Run(); // Таймер відліку часу
};
void timerClass::Run()
{
    clock_t t1 = clock();
    while((clock()/CLOCKS_PER_SEC - t1/CLOCKS_PER_SEC)< s);
    cout << "\a"; // Подання звукового сигналу
}

int main()
{
    timerClass ObjA(10); // Створення об'єкта класу
    ObjA.Run();
    char str[80];
    cout << "Введiть кiлькiсть секунд: ";
    cin >> str;
    timerClass ObjB(str); // Динамічна ініціалізація конструктора
    ObjB.Run();
    int xv, sec;
    cout << "Введiть хвилини i секунди: "; cin >> xv >> sec;
    timerClass ObjC(xv, sec); // Динамічна ініціалізація конструктора
    ObjC.Run();
    int hod;
    cout << "Введiть години, хвилини i секунди: "; cin >> hod >> xv >> sec;
    timerClass ObjD(hod, xv, sec); // Динамічна ініціалізація конструктора
    ObjD.Run();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

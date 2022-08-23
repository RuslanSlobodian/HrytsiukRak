//Код програми 3.4. Демонстрація механізму використання перевизначених конструкторів

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
    timerClass ObjA(10), ObjB("20"), ObjC(1, 10), ObjD(0, 2, 8);
    ObjA.Run(); // Відлік 10 секунд
    ObjB.Run(); // Відлік 20 секунд
    ObjC.Run(); // Відлік 1 хвилини і 10 секунд
    ObjD.Run(); // відлік 0 годин 2 хвилини і 8 секунд

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 11.17. Демонстрація механізму використання покажчиків на члени класу (початкова версія)


#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class myClass { 		      // Оголошення класового типу
public:
    int sum;
    void myClass::Sum(int x);
};

void myClass::Sum(int x)
{
    sum = 0;
    for(int i=x; i; i--) sum += i;
}

int main()
{
    int myClass::*dp; 		     // Покажчик на int-члена класу
    void (myClass::*fp)(int x); // Покажчик на функцію-члена

    myClass ObjC;

    dp = myClass::sum; // Отримуємо адресу члена даних
    fp = &myClass::Sum; // Отримуємо адресу функції-члена класу

    (ObjC.*fp)(7); // Обчислюємо суму чисел від 1 до 7
    cout << "Сума чисел від 1 до 7 дорівнює " << ObjC.*dp;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

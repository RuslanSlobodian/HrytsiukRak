//Код програми 11.17. Демонстрація механізму використання покажчиків на члени класу (початкова версія)


#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class MyClass { 		      // Оголошення класового типу
public:
    int sum;
    void myClass::Sum(int x);
};

void MyClass::Sum(int x)
{
    sum = 0;
    for(int i=x; i; i--) sum += i;
}

int main()
{
    int MyClass::*dp; 		     // Покажчик на int-члена класу
    void (MyClass::*fp)(int x); // Покажчик на функцію-члена

    MyClass ObjC;

    dp = myClass::sum; // Отримуємо адресу члена даних
    fp = &MyClass::Sum; // Отримуємо адресу функції-члена класу

    (ObjC.*fp)(7); // Обчислюємо суму чисел від 1 до 7
    cout << "Сума чисел від 1 до 7 дорівнює " << ObjC.*dp;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

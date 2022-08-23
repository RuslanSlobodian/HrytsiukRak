//Код програми 11.18. Демонстрація механізму використання покажчиків на члени класу (модифікована версія)

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class myClass { 		     // Оголошення класового типу
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
    int myClass::*dp; 		    // Покажчик на int-члена класу
    void (myClass::*fp)(int x); // Покажчик на функцію-члена
    myClass *c, ObjD; 	    // Член c зараз -- покажчик на об'єкт

    c = &ObjD; // Присвоюємо покажчику c адресу об'єкта
    dp = &myClass::sum; // Отримуємо адресу члена даних sum
    fp = &myClass::Sum; // Отримуємо адресу функції Sum()
    (c->*fp)(7); // Тепер використовуємо оператор "->*" для виклику 		функції Sum().
    cout << "Сума чисел від 1 до 7 дорівнює " << c->*dp; // ->*

    //system("PAUSE");
    return EXIT_SUCCESS;
}

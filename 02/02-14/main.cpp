//Код програми 2.14. Демонстрація механізму використання покажчика на об'єкт

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class pClass { 			// Оголошення класового типу
    int num;
public:
    void Set(int n) { num = n; }
    void Show() { cout << "num= " << num << endl; }
};

int main()
{
    pClass Obj, *p; 	// Створення об'єкта класу і покажчика на нього.

    Obj.Set(1);  		// Отримуємо прямий доступ до об'єкта Obj.
    Obj.Show();

    p = &Obj;  // Присвоюємо покажчику p адресу об'єкта Obj.
    p->Show(); // Отримуємо доступ до об'єкта Obj за допомогою покажчика.

    //system("PAUSE");
    return EXIT_SUCCESS;
}

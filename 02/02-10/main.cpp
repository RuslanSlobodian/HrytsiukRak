//Код програми 2.10. Демонстрація механізму використання вбудованих функцій у визначенні класу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class myClass { 			// Оголошення класового типу
    int c; 					// Закритий член за замовчуванням
public:
    // Автоматично вбудовані функції
    int Put() { return c; }
    void Get(int d) { c = d; }
};

int main()
{
    myClass Obj; 			// Створення об'єкта класу
    Obj.Get(10);
    cout << "c= " << Obj.Put() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 6.4. Демонстрація механізму ієрархії успадкування віртуальних функцій

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class BaseClass { 			// Оголошення базового класу
public:
    virtual void Show() { cout << "Базовий клас." << endl; }
};
class firstD : public BaseClass { 	// Клас firstD виведений з класу baseClass
public:
    void Show() { cout << "Перший похiдний клас." << endl; }
};
class secondD : public firstD { // Клас secondD виведений з класу 	firstD
    // Функція Show() тут взагалі не визначена.
};
int main()
{
    BaseClass ObjB;		// Створення об'єкта базового типу
    BaseClass *bp;		 // Створення покажчика на об'єкт базового типу
    firstD ObjF;			 // Створення об'єкта похідного типу
    secondD ObjS; 		// Створення об'єкта похідного типу

    bp = &ObjB; 		// Присвоєння покажчику адреси об'єкта базового класу
    bp->Show(); 		// Доступ до функції Show() класу baseClass
    bp = &ObjF; 		// Присвоєння покажчику адреси об'єкта похідного класу
    bp->Show(); 		// Доступ до функції Show() класу firstD
    bp = &ObjS; 		// Присвоєння покажчику адреси об'єкта похідного класу
    bp->Show(); /* 		Тут здійснюється звернення до функції Show() класу
                        baseClass, оскільки у класі secondD вона не перевизначена. */

    //	system("PAUSE");
    return EXIT_SUCCESS;
}

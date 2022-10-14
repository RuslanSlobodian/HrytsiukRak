//Код програми 6.1. Демонстрація механізму використання покажчиків набазовий клас для доступу до об'єктів похідних класів

#include <cstring>	 		// Для роботи з рядковими типами даних
#include <iostream>		 	// Для потокового введення-виведення
#include <cstdlib>			// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class BaseClass { 		// Оголошення класового типу
    char author[80];
public:
    void putAuthor(char *s) { strcpy(author, s); }
    void showAuthor() { cout << "Автор: "<< author << endl; }
};
class derivClass : public BaseClass { // Оголошення класового типу
    char title[80];
public:
    void putTitle(char *n) { strcpy(title, n); }
    void showTitle() { cout << "Назва: " << title << endl; }
};
int main()
{
    BaseClass *bp;		 // Створення покажчика на об'єкт базового типу
    BaseClass ObjB; 		// Створення об'єкта базового типу
    derivClass *dp; 		// Створення покажчика на об'єкт похідного типу
    derivClass ObjD; 		// Створення об'єкта похідного типу
    // Доступ до класу baseClass через покажчик.
    bp = &ObjB; 		// Присвоєння покажчику адреси об'єкта базового классу

    bp->putAuthor("Емiль Золя");

    // Доступ до класу derivClass через "базовий" 	покажчик.
    bp = &ObjD;		 // Присвоєння покажчику адреси об'єкта похідного класу
    bp->putAuthor("Вiльям Шекспiр");

    ObjB.showAuthor();	 // Покажемо, що кожен автор належить до відповідного об'єкта.
    ObjD.showAuthor();
    cout << endl;
    /* Оскільки функції putTitle() i showTitle() не є частиною базового класу, то вонинедоступні через "базовий" покажчик bp, i тому до 		них потрібно звертатисяабо безпосередньо, або, як показано тут, 		через покажчик на похідний тип. */

    dp = &ObjD;		 // Присвоєння покажчику адреси об'єкта похідного класу
    dp->putTitle("Буря");
    dp->showAuthor();	 // Тут можна використовувати або покажчик bp, або покажчик dp.
    dp->showTitle();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

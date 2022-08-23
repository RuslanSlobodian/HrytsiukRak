//Код програми 6.2. Демонстрацiя механiзму застосування вiртуальних функцiй

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бiблiотека С++

using namespace std; // Використання стандартного простору iмен

class baseClass { 			// Оголошення базового класу
public:
    // Оголошення вiртуальної функцiї
    virtual void Show() { cout << "Базовий клас." << endl; }
};

class firstD : public baseClass {
public:
    // Перевизначення функцiї Show() для 							класу firstD.
    void Show() { cout << "Перший похiдний клас." << endl; }
};
class secondD : public baseClass {
public:
    // Перевизначення функцiї Show() для 							класу secondD.
    void Show() { cout << "Другий похiдний клас." << endl; }
};
int main()
{
    baseClass ObjB; 		// Створення об'єкта базового типу
    baseClass *bp; 		// Створення покажчика на об'єкт базового типу
    firstD ObjF; 		// Створення об'єкта похiдного типу
    secondD ObjS; 		// Створення об'єкта похiдного типу
    bp = &ObjB;		 // Присвоєння покажчику адреси об'єкта 						базового класу
    bp->Show(); 		// Доступ до функцiї Show() класу 								baseClass
    bp = &ObjF; 		// Присвоєння покажчику адреси об'єкта 							похiдного класу
    bp->Show(); 		// Доступ до функцiї Show() класу firstD
    bp = &ObjS; 		// Присвоєння покажчику адреси об'єкта 							похiдного класу
    bp->Show(); 		// Доступ до функцiї Show() класу secondD

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 6.7. Демонстрацiя не коректної програми, яка у класi circle немаєперевизначення функцiї Show()

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бiблiотека С++

using namespace std; 			// Використання стандартного простору iмен

class figure {
protected:
    double x, y;
public:
    void Set(double _x, double _y) { x = _x; y = _y; }
    virtual void Show() = 0; // Суто вiртуальна функцiя
};

class triangle : public figure {
public:
    void Show()
    {
        cout << "Трикутник з висотою " << x; cout << " i основою " << y;
        cout << " має площу " << x * 0.5 * y ; cout << " кв. од." << endl;
    }
};
class rectangle : public figure {
public:
    void Show()
    {
        cout << "Прямокутник розмiрами " << x << " x " << y;
        cout << " має площу " << x * y ; cout << " кв. од."	<< endl;
    }
};
class circle : public figure {
    // Вiдсутнiсть визначення функцiї Show()
    // Викличе повiдомлення про помилку.
};
int main()
{
    figure *p; 		// Створення покажчика на об'єкт базового типу
    triangle ObjT;	 // Створення об'єкта похiдного типу
    rectangle ObjR;	 // Створення об'єкта похiдного типу
    //		circle ObjC; 	// Помилка: створення цього об'єкта є 							   неможливим!
    p = &ObjT;		 // Присвоєння покажчику адреси об'єкта 						    похідного класу
    p->Set(10.3, 5.5);
    p->Show();
    p = &ObjR; 		// Присвоєння покажчику адреси об'єкта 							   похідного класу
    p->Set(10.3, 5.5);
    p->Show();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

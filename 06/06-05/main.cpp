//Код програми 6.5. Демонстрацiя механiзму застосування вiртуальних  функцiй

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бiблiотека С++

using namespace std; // Використання стандартного простору iмен

class figure {
protected:
    double x, y;
public:
    void Set(double _x, double _y) { x = _x; y = _y; }
    virtual void Show()
    {
        cout << "У цьому класi виразу для обчислення площi не визначено." << endl;
    }
};
class triangle : public figure {
public:
    void Show()
    {
        cout << "Трикутник з висотою " << x; cout << " i основою " << y;
        cout << " має площу " << x * 0.5 * y ; cout << " кв. од." 	<< endl;
    }
};
class rectangle : public figure {
public:
    void Show()
    {
        cout << "Прямокутник розмiрами " << x << " x " << y;
        cout << " має площу " << x * y ; cout << " кв. од." 			<< endl;
    }
};

int main()
{
    figure *p; // Створення покажчика на об'єкт базового типу
    triangle ObjT; // Створення об'єктiв похiдних типiв
    rectangle ObjR; // Створення об'єкта похідного типу
    p = &ObjT; // Присвоєння покажчику адреси об'єкта похідного класу
    p->Set(10.3, 5.5);
    p->Show();
    p = &ObjR; // Присвоєння покажчику адреси об'єкта похідного 			класу
    p->Set(10.3, 5.5);
    p->Show();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

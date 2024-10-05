// Код програми 6.7. Демонстрацiя не коректної програми, яка у класi Circle не має перевизначення методу show()

#include <iostream>
#include <cstdlib>

using namespace std;

class Figure {                  // Оголошення абстрактного базового класу
protected:
    double x;
    double y;
public:
    void set(double x, double y) {
        this->x = x;
        this->y = y;
    }

    virtual void show() = 0;    // абстрактний метод, або суто вiртуальний метод
};

class Triangle : public Figure {
public:
    void show() {
        cout << "Трикутник з висотою " << x;
        cout << " i основою " << y;
        cout << " має площу " << x * 0.5 * y;
        cout << " кв. од." << endl;
    }
};

class Rectangle : public Figure {
public:
    void show() {
        cout << "Прямокутник розмiрами " << x << " x " << y;
        cout << " має площу " << x * y;
        cout << " кв. од." << endl;
    }
};

class Circle : public Figure {
    // Вiдсутнiсть визначення методу show() викличе повiдомлення про помилку
};

int main() {
    system("chcp 65001");
    Figure* figurePtr;          // Створення вказівника на об'єкт базового класу
//        Figure figure; 	    // Помилка: створення цього об'єкта є неможливим!
    Triangle triangle;          // Створення об'єкта похiдного класу
    Rectangle rectangle;        // Створення об'єкта похiдного класу
//    Circle circle; 	        // Помилка: створення цього об'єкта є неможливим!
    figurePtr = &triangle;      // Присвоєння вказівнику адреси об'єкта похідного класу
    figurePtr->set(10.3, 5.5);
    figurePtr->show();
    figurePtr = &rectangle;     // Присвоєння вказівнику адреси об'єкта похідного класу
    figurePtr->set(10.3, 5.5);
    figurePtr->show();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

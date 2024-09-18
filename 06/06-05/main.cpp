// Код програми 6.5. Демонстрацiя механiзму застосування вiртуальних методів

#include <iostream>
#include <cstdlib>

using namespace std;

class Figure {
protected:
    double x;
    double y;
public:
    void set(double x, double y) {
        this->x = x;
        this->y = y;
    }

    virtual void show() {
        cout << "У цьому класi виразу для обчислення площi не визначено" << endl;
    }
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

int main() {
    system("chcp 65001");
    Figure* figurePtr;          // Створення вказівника на об'єкт базового класу
    Triangle triangle;          // Створення об'єкта похiдного класу
    Rectangle rectangle;        // Створення об'єкта похідного класу
    figurePtr = &triangle;      // Присвоєння вказівнику адреси об'єкта похідного класу
    figurePtr->set(10.3, 5.5);
    figurePtr->show();
    figurePtr = &rectangle;     // Присвоєння вказівнику адреси об'єкта похідного класу
    figurePtr->set(10.3, 5.5);
    figurePtr->show();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Код програми 6.6. Демонстрацiя механiзму надання параметру вiртуального методу значення, що дiє за замовчуванням

#include <iostream>
#include <cstdlib>

using namespace std;

class Figure {
protected:
    double x;
    double y;
public:
    void set(double x, double y = 0) {
        this->x = x;
        this->y = y;
    }

    virtual void show() {
        cout << "У цьому класі вираз для обчислення площі не визначено" << endl;
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

class Circle : public Figure {
public:
    void show() {
        cout << "Круг з радiусом " << x;
        cout << " має площу " << 3.14159 * x * x;
        cout << " кв. од." << endl;
    }
};

int main() {
    system("chcp 65001");
    Figure *figurePtr;          // Створення вказівника на об'єкт базового класу
    Triangle triangle;          // Створення об'єкта похiдного класу
    Rectangle rectangle;        // Створення об'єкта похiдного класу
    Circle circle;              // Створення об'єкта похiдного класу

    figurePtr = &triangle;      // Присвоєння вказівнику адреси об'єкта похiдного класу
    figurePtr->set(10.3, 5.5);
    figurePtr->show();

    figurePtr = &rectangle;     // Присвоєння вказівнику адреси об'єкта похідного класу
    figurePtr->set(10.3, 5.5);
    figurePtr->show();
    figurePtr = &circle;        // Присвоєння вказівнику адреси об'єкта похідного класу
    figurePtr->set(9.67);
    figurePtr->show();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

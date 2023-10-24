// Код програми 10.4. Демонстрація ефективності використання засобу динамічної ідентифікації типів

#include <iostream>
#include <cstdlib>

using namespace std;

class Figure {
protected:
    double x, y;
public:
    Figure(double x, double y) {
        this->x = x;
        this->y = y;
    }

    virtual double area() = 0;
};

class Triangle : public Figure {
public:
    Triangle(double x, double y) : Figure(x, y) {}

    double area() { return x * 0.5 * y; }
};

class Rectangle : public Figure {
public:
    Rectangle(double x, double y) : Figure(x, y) {}

    double area() { return x * y; }
};

class Circle : public Figure {
public:
    Circle(double x, double y = 0) : Figure(x, y) {}

    double area() { return 3.14 * x * x; }
};

// Генератор об'єктів класу Figure
Figure* factory() {
    switch (rand() % 3) {
        case 0:
            return new Circle(10.0);
        case 1:
            return new Triangle(10.1, 5.3);
        case 2:
            return new Rectangle(4.3, 5.7);
    }
    return 0;
}

int main() {
    system("chcp 65001");
    Figure* figurePtr;          // Вказівник на базовий класс

    int triangleCounter = 0;
    int rectangleCounter = 0;
    int circleCounter = 0;

    // Генеруємо і підраховуємо об'єкти
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        figurePtr = factory();  // Генеруємо об'єкт
        cout << "Об'єкт має тип " << typeid(*figurePtr).name();
        cout << ". ";

        // Враховуємо цей об'єкт
        if (typeid(*figurePtr) == typeid(Triangle)) triangleCounter++;
        if (typeid(*figurePtr) == typeid(Rectangle)) rectangleCounter++;
        if (typeid(*figurePtr) == typeid(Circle)) circleCounter++;

        // Відображаємо площу фігури
        cout << "Площа дорiвнює " << figurePtr->area() << endl;
    }
    cout << endl;
    cout << "Згенеровано такi об'єкти:" << endl;
    cout << " трикутникiв: " << triangleCounter << endl;
    cout << " прямокутників: " << rectangleCounter << endl;
    cout << " кругiв: " << circleCounter << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

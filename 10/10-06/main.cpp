// Код програми 10.6. Демонстрація механізму застосування оператора typeid до шаблонної версії Figure-ієрархії класів

#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
class Figure {
protected:
    T x;
    T y;
public:
    Figure(T x, T y) {
        this->x = x;
        this->y = y;
    }

    virtual T area() = 0;
};

template<typename T>
class Triangle : public Figure<T> {
public:
    Triangle(T x, T y) : Figure<T>(x, y) {}

    T area() {
        return Figure<T>::x * 0.5 * Figure<T>::y;
    }
};

template<typename T>
class Rectangle : public Figure<T> {
public:
    Rectangle(T x, T y) : Figure<T>(x, y) {}

    T area() {
        return Figure<T>::x * Figure<T>::y;
    }
};

template<typename T>
class Circle : public Figure<T> {
public:
    Circle(T x, T y = 0) : Figure<T>(x, y) {}

    T area() {
        return 3.14 * Figure<T>::x * Figure<T>::x;
    }
};

// Генератор об'єктів, що утворюється з класу Figure
Figure<double>* generator() {
    switch (rand() % 3) {
        case 0:
            return new Circle<double>(10.0);
        case 1:
            return new Triangle<double>(10.1, 5.3);
        case 2:
            return new Rectangle<double>(4.3, 5.7);
    }
    return nullptr;
}

int main() {
    system("chcp 65001");
    Figure<double>* figurePtr;

    int triangleCounter = 0;
    int rectangleCounter = 0;
    int circleCounter = 0;

    // Генеруємо і підраховуємо об'єкти
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        figurePtr = generator();
        cout << "Об'єкт має тип " << typeid(*figurePtr).name();
        cout << ". ";

        // Враховуємо об'єкт
        if (typeid(*figurePtr) == typeid(Triangle<double>)) triangleCounter++;
        if (typeid(*figurePtr) == typeid(Rectangle<double>)) rectangleCounter++;
        if (typeid(*figurePtr) == typeid(Circle<double>)) circleCounter++;

        cout << "Площа дорівнює " << figurePtr->area() << endl;
    }
    cout << endl;
    cout << "Згенеровано такі об'єкти:" << endl;
    cout << " трикутників: " << triangleCounter << endl;
    cout << " прямокутників: " << rectangleCounter << endl;
    cout << " кругів: " << circleCounter << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

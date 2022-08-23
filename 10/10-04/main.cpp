//Код програми 10.4. Демонстрація ефективності використання засобу динамічної ідентифікації типів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <typeinfo> 		// Для динамічної ідентифікації типів

using namespace std; 			// Використання стандартного простору імен

class figure {
protected:
    double x, y;
public:
    figure(double _x, double _y) { x = _x; y = _y; }
    virtual double area() = 0;
};
class triangle: public figure {
public:
    triangle(double _x, double _y): figure(_x, _y) {}
    double area() { return x * 0.5 * y; }
};

class rectangle: public figure {
public:
    rectangle(double _x, double _y): figure(_x, _y) {}
    double area() { return x * y; }
};
class circle: public figure {
public:
    circle(double _x, double _y=0): figure(_x, _y) {}
    double area() { return 3.14 * x * x; }
};
// Генератор об'єктів класу figure.
figure *factory() {
    switch(rand() % 3) {
    case 0: return new circle(10.0);
    case 1: return new triangle(10.1, 5.3);
    case 2: return new rectangle(4.3, 5.7);
    }
    return 0;
}
int main()
{
    figure *p; // Покажчик на базовий класс

    int t = 0, r = 0, c = 0;

    // Генеруємо і підраховуємо об'єкти
    for(int i=0; i<10; i++) {
        p = factory(); // Генеруємо об'єкт
        cout << "Об'єкт має тип " << typeid(*p).name();
        cout << ". ";

        // Враховуємо цей об'єкт
        if(typeid(*p) == typeid(triangle)) t++;
        if(typeid(*p) == typeid(rectangle)) r++;
        if(typeid(*p) == typeid(circle)) c++;

        // Відображаємо площу фігури
        cout << "Площа дорiвнює " << p->area() << endl;
    }
    cout << endl;
    cout << "Згенеровано такi об'єкти:" << endl;
    cout << " трикутникiв: " << t << endl;
    cout << " прямокутників: " << r << endl;
    cout << " кругiв: " << c << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

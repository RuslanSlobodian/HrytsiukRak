//Код програми 10.6. Демонстрація механізму застосування оператора typeid до шаблонної версії figure-ієрархії класів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <typeinfo> 		// Для динамічної ідентифікації типів

using namespace std; 			// Використання стандартного простору імен

template <class aType> class figure {
protected:
    aType x, y;
public:
    figure(aType _x, aType _y) { x = _x; y = _y; }
    virtual aType area() = 0;
};
template <class aType> class triangle: public figure<aType> {
public:
    triangle(aType _x, aType _y): figure<aType>(_x, _y) {;}
    aType area() { return figure<aType>::x * 0.5 * figure<aType>::y; }
};
template <class aType> class rectangle: public figure<aType> {
public:
    rectangle(aType _x, aType _y): figure<aType>(_x, _y) {}
    aType area() { return figure<aType>::x * figure<aType>::y; }
};
template <class aType> class circle: public figure<aType> {
public:
    circle(aType _x, aType _y=0): figure<aType>(_x, _y) {}
    aType area() { return 3.14 * figure<aType>::x * figure<aType>::x; }
};

// Генератор об'єктів, що утворюється з класу figure.
figure<double> *generator()
{

    switch(rand() % 3) {
    case 0: return new circle<double>(10.0);
    case 1: return new triangle<double>(10.1, 5.3);
    case 2: return new rectangle<double>(4.3, 5.7);

    }
}
int main()
{
    figure<double> *p;
    int t = 0, c = 0, r = 0;

    // Генеруємо і підраховуємо об'єкти
    for(int i=0; i<10; i++) {

        p = generator();
        cout << "Об'єкт має тип " << typeid(*p).name();
        cout << ". ";

        // Враховуємо об'єкт
        if(typeid(*p) == typeid(triangle<double>)) t++;
        if(typeid(*p) == typeid(rectangle<double>)) r++;
        if(typeid(*p) == typeid(circle<double>)) c++;

        cout << "Площа дорівнює " << p->area() << endl;
    }
    cout << endl;
    cout << "Згенеровано такі об'єкти:" << endl;
    cout << " трикутників: " << t << endl;
    cout << " прямокутників: " << r << endl;
    cout << " кругів: " << c << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

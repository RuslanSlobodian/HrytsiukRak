// Код програми 2.3. Демонстрація механізму використання параметризованого конструктора

#include <iostream>		 		// Для потокового введення-виведення
#include <math.h>			 	// Для використання математичних функцій
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
private:
    double a;
    int index;                  // Містить ідентифікаційний номер об'єкта
public:
    MyClass(int n);             // Оголошення параметризованого конструктора
    ~MyClass();                 // Оголошення деструктора
    void setData(double, double); 	// Введення в об'єкт значення
    double getData(); 			// Виведення з об'єкта значення
};

// Визначення параметризованого конструктора
MyClass::MyClass(int n) {
    a = 0;
    index = n;
    cout << "Об'єкт " << index << " iнiцiалiзовано" << endl;
}

// Визначення деструктора
MyClass::~MyClass() {
    cout << "Об'єкт " << index << " зруйновано" << endl;
}

// Введення в об'єкт значення
void MyClass::setData(double x, double y) {
    double a1 = pow(x,1.3);
    double a2 = pow(fabs(3.2*x - y),0.4);
    double a3 = pow(pow(cos(a2),2),1./3);
    a = a1+a3;
}

// Виведення з об'єкта значення
double MyClass::getData() {
    return a;
}

int main() {
    // Створення та ініціалізація двох об'єктів
    MyClass objectA(1);
    MyClass objectB(2);

    double x = 2.6;
    double y = 7.1;

    objectA.setData(x,y);
    objectB.setData(x+y,y/x);

    cout << "Вмiст об'єкта objectA: " << objectA.getData() << endl;
    cout << "Вмiст об'єкта objectB: " << objectB.getData() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

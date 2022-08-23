//Код програми 5.8. Демонстраціямеханізму успадкування декількох базових класів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class baseA {	 // Оголошення базового класу
protected:
    int x;
public:
    void showX() { cout << x << endl; }
};

class baseB { // Оголошення базового класу
protected:
    int y;
public:
    void showY() { cout << y << endl; }
};

// Успадкування двох базових класів.
// Оголошення похідного класу
class derived : public baseA, public baseB { // Оголошення базового класу
public:
    void setXY(int c, int d) {x = c; y = d; }
};
int main()
{
    derived ObjD; // Створення об'єкта класу
    ObjD.setXY(10, 20); // Член класу derived
    ObjD.showX(); // Функція зкласу baseA
    ObjD.showY(); // Функція зкласу baseB

    //system("PAUSE");
    return EXIT_SUCCESS;
}

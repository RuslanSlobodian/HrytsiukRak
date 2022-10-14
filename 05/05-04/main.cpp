//Код програми 5.4. Демонстрація механізму доступу до захищених членів базового класу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class BaseClass {		 // Оголошення базового класу
protected:
    int c, d;   // Ці члени закриті у класі baseClass але доступні для класу derived.
public:
    void setB(int a, int b) { c = a; d = b; }
    void showB(char *s) { cout << s << "c= " << c << "; d= " << d << endl; }
};

// Оголошення похідного класу
class Derived : public BaseClass {
    int f;
public:
    // Клас derived має доступ до членів класу baseClass c та d.
    void setF() 			{ f = c*d; }
    void showF(char *b, char *p) { showB(b); cout << p << "f= " << f << endl; }
};

int main()
{
    Derived ObjD; // Створення об'єкта класу
    // OK, класу derived це робити дозволено.
    ObjD.setB(2, 3);
    // OK, класу derived це робити дозволено.
    ObjD.showB("Базовий клас: "); cout << endl;
    // Функція setF() належить класу derived.
    ObjD.setF();
    // Функція showF() належить класу derived.
    ObjD.showF("Базовий клас: ", "Похідний клас: ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

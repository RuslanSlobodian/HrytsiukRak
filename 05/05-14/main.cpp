//Код програми 5.14. Демонстрація механізму передачі аргументів конструкторам базового класу через конструктори похідного класу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class BaseA { 		// Оголошення базового класу
protected:
    int c;
public:
    BaseA(int x) 	{ c = x; cout << "Створення baseA-об'єкта" << endl; }
    ~BaseA()		 { cout << "Руйнування baseA-об'єкта" << endl; }
};

class BaseB {	 // Оголошення базового класу
protected:
    int f;
public:
    BaseB(int x) { f = x; cout << "Створення baseB-об'єкта" << endl; }
    ~BaseB() { cout << "Руйнування baseB-об'єкта" << endl; }
};

// Оголошення похідного класу
class Derived : public BaseA, public BaseB {
public:
    /* Конструктор класу derived не використовує параметрів, але повинен
        оголосити їх, щоб передати конструкторам базових класів. */

    Derived(int x, int y) : BaseA(x), BaseB(y)
    { cout << "Створення derived-об'єкта" << endl; }
    ~Derived() { cout << "Руйнування derived-об'єкта" << endl; }
    void showB(char *s)
    { cout << s << "c =" << c << "; f= " << f << endl; }
};

int main()
{
    Derived ObjD(3, 4);

    ObjD.showB("Базовий клас: "); // Відображає числа c= 3; f= 4

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 5.13. Демонстраціямеханізму передачі параметрів конструкторамдекількох базових класів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class baseA {		 // Оголошення базового класу
protected:
    int c;
public:
    baseA(int x) { c = x; cout << "Створення baseA-об'єкта" << endl; }
    ~baseA() { cout << "Руйнування baseA-об'єкта" << endl; }
};

// Оголошення базового класу
class baseB { // Оголошення базового класу
protected:
    int f;
public:
    baseB(int x) { f = x; cout << "Створення baseB-об'єкта" << endl; }
    ~baseB() { cout << "Руйнування baseB-об'єкта" << endl; }
};

// Оголошення похідного класу
class derived : public baseA, public baseB {
    int d;
public:
    derived(int x, int y, int z): baseA(y), baseB(z)
    { d = x; cout << "Створення derived-об'єкта" << endl; }
    ~derived() { cout << "Руйнування derived-об'єкта" << endl; }
    void showB(char *s) {cout << s << "c= " << c << "; d= " << d << "; f= " << f << endl; }
};

int main()
{
    derived ObjD(3, 4, 5);
    ObjD.showB("Базовий клас: "); // Відображає числа c= 4; d= 3; f= 5

    //system("PAUSE");
    return EXIT_SUCCESS;
}

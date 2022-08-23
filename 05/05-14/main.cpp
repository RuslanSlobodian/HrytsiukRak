//Код програми 5.14. Демонстрація механізму передачі аргументів конструкторам базового класу через конструктори похідного класу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class baseA { 		// Оголошення базового класу
protected:
    int c;
public:
    baseA(int x) 	{ c = x; cout << "Створення baseA-об'єкта" << endl; }
    ~baseA()		 { cout << "Руйнування baseA-об'єкта" << endl; }
};

class baseB {	 // Оголошення базового класу
protected:
    int f;
public:
    baseB(int x) { f = x; cout << "Створення baseB-об'єкта" << endl; }
    ~baseB() { cout << "Руйнування baseB-об'єкта" << endl; }
};

// Оголошення похідного класу
class derived : public baseA, public baseB {
public:
    /* Конструктор класу derived не використовує параметрів, але повинен
        оголосити їх, щоб передати конструкторам базових класів. */

    derived(int x, int y) : baseA(x), baseB(y)
    { cout << "Створення derived-об'єкта" << endl; }
    ~derived() { cout << "Руйнування derived-об'єкта" << endl; }
    void showB(char *s)
    { cout << s << "c =" << c << "; f= " << f << endl; }
};

int main()
{
    derived ObjD(3, 4);

    ObjD.showB("Базовий клас: "); // Відображає числа c= 3; f= 4

    //system("PAUSE");
    return EXIT_SUCCESS;
}

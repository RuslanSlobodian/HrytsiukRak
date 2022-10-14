//Код програми 5.12. Демонстраціямеханізму передачі параметрів конструкторамбазового класу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class BaseClass { // Оголошення базового класу
protected:
    int c;
public:
    BaseClass(int x) { c = x; cout << "Створення baseClass-об'єкта" << 	endl; }
    ~BaseClass() { cout << "Руйнування baseClass-об'єкта" << endl; }
};

// Оголошення похідного класу
class Derived : public BaseClass {
    int d;
public:
    // Клас derived використовує параметр x, a параметр y
    // передається конструктору класу baseClass.
    Derived(int x, int y) : BaseClass(y)
        { d = x; cout << "Створення derived-об'єкта" << endl; }
    ~Derived() { cout << "Руйнування derived-об'єкта" << endl; }
    void showB(char *s)
        { cout << s << "c= " << c << "; d= " << d << endl; }
};

int main()
{
    Derived ObjD(3, 4);
    ObjD.showB("Базовий клас: "); // Відображає числа 4 3

//system("PAUSE");
return EXIT_SUCCESS;
}

//Код програми 5.12. Демонстраціямеханізму передачі параметрів конструкторамбазового класу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class baseClass { // Оголошення базового класу
protected:
    int c;
public:
    baseClass(int x) { c = x; cout << "Створення baseClass-об'єкта" << 	endl; }
    ~baseClass() { cout << "Руйнування baseClass-об'єкта" << endl; }
};

// Оголошення похідного класу
class derived : public baseClass {
    int d;
public:
    // Клас derived використовує параметр x, a параметр y
    // передається конструктору класу baseClass.
    derived(int x, int y) : baseClass(y)
        { d = x; cout << "Створення derived-об'єкта" << endl; }
    ~derived() { cout << "Руйнування derived-об'єкта" << endl; }
    void showB(char *s)
        { cout << s << "c= " << c << "; d= " << d << endl; }
};

int main()
{
    derived ObjD(3, 4);
    ObjD.showB("Базовий клас: "); // Відображає числа 4 3

//system("PAUSE");
return EXIT_SUCCESS;
}

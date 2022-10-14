//Код програми 5.7. Демонстраціямеханізму використання специфікатора доступу protected для успадкування базового класу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; // Використання стандартного простору імен

class BaseClass 		{ // Оголошення базового класу
    int c; 		// Закритий
protected:
    int d;		 // Захищений
public:
    int f;		 // Відкритий
    void Set(int a) { c = a; }
    int Put() { return c; }
};

// Успадковуємо клас baseClass як protected-клас.
class Derived : protected BaseClass {
public:
    void setJ(int a) { d = a; } // d - тут protected-член
    void setF(int a) { f = a; } // f - тут protected-член
    int getJ() { return d; }
    int getK() { return f; }
};

int main()
{
    Derived ObjD; // Створення об'єкта класу
    /* Наступний рядок неправомірний, оскількифункція Set() є
        protected-членом класу derived, що робить його недоступним за його межами. */
    //		ObjD.Set(10);
    //    	cout << ObjD.Put(); 	// Неправильно, оскількифункція Put() -- protected-член.
    //		ObjD.f = 10; 	// Неправильно, оскільки змінна f - protected-член
    // Наступні настанови правомірні.
    ObjD.setF(10);
    cout << ObjD.getK() << " ";
    ObjD.setJ(12);
    cout << ObjD.getJ() << " ";


    system("PAUSE");
    return EXIT_SUCCESS;
}

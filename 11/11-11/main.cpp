//Код програми 11.11. Демонстрація механізму використання модифікатора mutable


#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class Demo {
    mutable int c;
    int d;
public:
    int Put() const { return c; } 	// Все гаразд

    void Set(int x) const
    {
        c = x; // тепер все гаразд
    };

    void setJ(int x) const // Наступна функція не відкомпілюється.
    {
        d = x; // Це, як і раніше, неправильно!
    }
};
int main()
{
    Demo Obj;
    Obj.Set(1900);
    cout << Obj.Put();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

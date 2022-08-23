//Код програми 11.10. Демонстрація механізму використання const-функцій-членів классу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class Demo {
    int c;
public:
    int Put() const {
        return c; // Все гаразд
    }
    void Set(int x) const
    {
        c = x; // Помилка!
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

//Код програми 11.9. Демонстрація механізму використання статичних членів-даних классу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class ShareVar {
    static int n;
public:
    void Set(int c) { n = c; }
    void Show() { cout << n << " "; }
};
int ShareVar::n; // Визначаємо static-член n

int main()
{
    ShareVar ObjA, ObjB;

    ObjA.Show(); // Виводиться 0
    ObjB.Show(); // Виводиться 0
    ObjA.Set(10); // Встановлюємо static-члена n дорівнює 10
    ObjA.Show(); // Виводиться 10
    ObjB.Show(); // Також виводиться 10
    //system("PAUSE");
    return EXIT_SUCCESS;
}

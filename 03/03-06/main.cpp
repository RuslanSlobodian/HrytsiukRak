//Код програми 3.6. Демонстрація механізму присвоєння об'єктів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class myClass { // Оголошення класового типу
    int a, b;
public:
    myClass() { a = b = 0; }
    void Set(int c, int d) { a = c; b = d; }
    void Show() { cout << "a = " << a << "; b = " << b << endl; }
};
int main()
{
    myClass ObjA, ObjB; // Створення об'єктів класу
    ObjA.Set(10, 20);
    ObjB.Set(0, 0);
    cout << "Об'єкт ObjA до присвоєння:" << endl;
    ObjA.Show();
    cout << "Об'єкт ObjB до присвоєння:" << endl;
    ObjB.Show();
    cout << endl;
    ObjB = ObjA; // Присвоюємо об'єкт ObjA об'єкту ObjB.
    cout << "Об'єкт ObjA пiсля виконання операцiї присвоєння:" << endl;
    ObjA.Show();
    cout << "Об'єкт ObjB пiсля виконання операцiї присвоєння:" << endl;
    ObjB.Show();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

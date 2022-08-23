//Код програми 4.12. Демонстрація механізму перевизначення оператора виклику  функцій "()"

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class kooClass { // Оголошення класового типу
    int x, y, z; // Тривимірні координати
public:
    kooClass() { x = y = z = 0; }
    kooClass(int c, int d, int f) {x = c; y = d; z = f; }
    kooClass operator()(int a, int b, int c);
    void Show(char *s);
};
// Перевизначення оператора виклику функцій "()".
kooClass kooClass::operator()(int a, int b, int c)
{
    kooClass tmp; // Створення тимчасового об'єкта
    tmp.x = x + a;
    tmp.y = y + b;
    tmp.z = z + c;
    return tmp; // Повертає модифікований тимчасовий об'єкт
}
// Відображення тривимірних координат x, y, z.
void kooClass::Show(char *s)
{
    cout << "Координати об'єкта <" << s << ">: ";
    cout << "\t\tx= " << x << ", y= " << y << ", z= " << z << endl;
}

int main()
{
    kooClass ObjA(1, 2, 3), ObjB;
    ObjB = ObjA(10, 11, 12); // Виклик функції operator()
    ObjA.Show("A");
    ObjB.Show("B");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

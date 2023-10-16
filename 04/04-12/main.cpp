//Код програми 4.12. Демонстрація механізму перевизначення оператора виклику  функцій "()"

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class Coordinates { // Оголошення класового типу
    int x, y, z; // Тривимірні координати
public:
    Coordinates() { x = y = z = 0; }
    Coordinates(int c, int d, int f) {x = c; y = d; z = f; }
    Coordinates operator()(int a, int b, int c);
    void Show(char *s);
};
// Перевизначення оператора виклику функцій "()".
Coordinates Coordinates::operator()(int a, int b, int c)
{
    Coordinates tmp; // Створення тимчасового об'єкта
    tmp.x = x + a;
    tmp.y = y + b;
    tmp.z = z + c;
    return tmp; // Повертає модифікований тимчасовий об'єкт
}
// Відображення тривимірних координат x, y, z.
void Coordinates::Show(char *s)
{
    cout << "Координати об'єкта <" << s << ">: ";
    cout << "\t\tx= " << x << ", y= " << y << ", z= " << z << endl;
}

int main()
{
    system("chcp 65001");
    Coordinates ObjA(1, 2, 3), ObjB;
    ObjB = ObjA(10, 11, 12); // Виклик функції operator()
    ObjA.Show("A");
    ObjB.Show("B");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 4.5. Демонстрація механізму перевизначення бінарних операторів
// множення "*" і ділення "/" з використанням функцій"друзів" класу

#include <cstdlib>
#include <iostream>

using namespace std; // Використання стандартного простору імен

class kooClass { // Оголошення класового типу
    int x, y, z; // Тривимірні координати
public:
    kooClass() {x = y = z = 0; }
    kooClass(int c, int d, int f) { x = c; y = d; z = f; }
    friend kooClass operator*(kooClass obi, int c);
    friend kooClass operator*(int c, kooClass obi);
    friend kooClass operator/(kooClass obi, int c);
    friend kooClass operator/(int c, kooClass obi);
    void Show(char *s);
};
// Операторна "дружня" функція класу.
// Перевизначення бінарного оператора множення "*".
kooClass operator*(kooClass obi, int c)
{
    kooClass tmp; // Створення тимчасового об'єкта
    tmp.x = obi.x * c;
    tmp.y = obi.y * c;
    tmp.z = obi.z * c;
    return tmp; // Повертає модифікований тимчасовий об'єкт
}
// Операторна "дружня" функція класу.
// Перевизначення бінарного оператора множення "*".
kooClass operator*(int c, kooClass obi)
{
    kooClass tmp; // Створення тимчасового об'єкта
    tmp.x = c * obi.x;
    tmp.y = c * obi.y;
    tmp.z = c * obi.z;
    return tmp; // Повертає модифікований тимчасовий об'єкт
}
// Перевизначення бінарного оператора ділення "/".
kooClass operator/(kooClass obi, int c)
{
    kooClass tmp; // Створення тимчасового об'єкта
    tmp.x = obi.x / c;
    tmp.y = obi.y / c;
    tmp.z = obi.z / c;
    return tmp; // Повертає модифікований тимчасовий об'єкт
}
// Перевизначення бінарного оператора ділення "/".
kooClass operator/(int c, kooClass obi)
{
    kooClass tmp; // Створення тимчасового об'єкта
    tmp.x = c / obi.x;
    tmp.y = c / obi.y;
    tmp.z = c / obi.z;
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
    kooClass ObjA(1, 2, 3), ObjB(10, 10, 10), ObjC;
    int a = 10, b = 5;
    ObjA.Show("A");
    ObjB.Show("B");
    ObjC = ObjA * a; // Множення об'єкта ObjA на число a
    ObjC.Show("C=A*a");
    ObjC = a * ObjA; // Множення числа a на об'єкт ObjA
    ObjC.Show("C=a*A");
    ObjC = ObjB / b; // Ділення об'єкта ObjB на число b
    ObjC.Show("C=B*b");
    ObjC = a / ObjB; // Ділення числа a на об'єкт ObjB
    ObjC.Show("C=a/B");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

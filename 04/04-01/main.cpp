//Код програми 4.1. Демонстрація механізму перевизначення бінарних операторів
//додавання "+" та присвоєння "=" за допомогою функцій-членів класу

#include <cstdlib>
#include <iostream>

using namespace std; // Використання стандартного простору імен

class kooClass { 			// Оголошення класового типу
    int x, y, z; 				// Тривимірні координати
public:
    kooClass() {x = y = z = 0; }
    kooClass(int c, int d, int f) {x = c; y = d; z = f; }
    kooClass operator+(kooClass obj); // Операнд obj передається неявно.
    kooClass operator=(kooClass obj); // Операнд obj передається неявно.
    void Show(char *s);
};
// Перевизначення бінарного оператора додавання "+".
kooClass kooClass::operator+(kooClass obj)
{
    kooClass tmp; // Створення тимчасового об'єкта
    tmp.x = x + obj.x; // Операції додавання цілочисельних значень
    tmp.y = y + obj.y; // зберігають початковий вміст операндів
    tmp.z = z + obj.z;

    return tmp; // Повертає модифікований тимчасовий об'єкт
}
// Перевизначення оператора присвоєння "=".
kooClass kooClass::operator=(kooClass obj)
{
    this->x = obj.x; // Операції присвоєння цілочисельних значень
    y = obj.y; // зберігають початковий вміст операндів
    z = obj.z;

    // Повернення модифікованого об'єкта операнда, адресованого покажчиком
    return *this;
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
    ObjA.Show("A");
    ObjB.Show("B");

    ObjC = ObjA + ObjB; // Додавання об'єктів ObjA і ObjB
    ObjC.Show("C=A+B");
    ObjC = ObjA + ObjB + ObjC; // Множинне додавання об'єктів
    ObjC.Show("C=A+B+C");
    ObjC = ObjB = ObjA; // Множинне присвоєння об'єктів
    ObjB.Show("B=A");
    ObjC.Show("C=B");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

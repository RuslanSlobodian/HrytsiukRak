//Код програми 4.4. Демонстрація механізму перевизначення бінарного оператора додавання "+" за допомогою "дружньої" функції класу

#include <cstdlib>
#include <iostream>

using namespace std; // Використання стандартного простору імен

class kooClass { // Оголошення класового типу
    int x, y, z; // Тривимірні координати
public:
    kooClass() {x = y = z = 0; }
    kooClass(int c, int d, int f) { x = c; y = d; z = f; }
    friend kooClass operator+(kooClass obi, kooClass obj);
    kooClass operator=(kooClass obj); // Операнд obj передається неявно.
    void Show(char *s);
};
// Операторна "дружня" функція класу.
// Перевизначення бінарного оператора додавання "+".
kooClass operator+(kooClass obi, kooClass obj)
{
    kooClass tmp; // Створення тимчасового об'єкта
    tmp.x = obi.x + obj.x;
    tmp.y = obi.y + obj.y;
    tmp.z = obi.z + obj.z;
    return tmp; // Повертає модифікований тимчасовий об'єкт
}
// Перевизначення оператора присвоєння "=".
kooClass kooClass::operator=(kooClass obj)
{
    x = obj.x;
    y = obj.y;
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
    ObjC = ObjB = ObjA ; // Множинне присвоєння об'єктів
    ObjC.Show("C=B");
    ObjB.Show("B=A");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

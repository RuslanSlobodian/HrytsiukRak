//Код програми 4.3. Демонстрація механізму перевизначення унарного оператора інкремента "++" з використанням його префіксної та пост-фіксної форм

#include <cstdlib>
#include <iostream>

using namespace std; // Використання стандартного простору імен

class kooClass { 			// Оголошення класового типу
    int x, y, z; 			// Тривимірні координати
public:
    kooClass() { x = y = z = 0; }
    kooClass(int c, int d, int f) {x = c; y = d; z = f; }
    kooClass operator*(kooClass obj); // Операнд obj передається неявно.
    kooClass operator=(kooClass obj); // Операнд obj передається неявно.
    kooClass operator++(); // Префіксна форма оператора інкремента "++"

    // Постфіксна форма оператора інкремента "++"
    kooClass operator++(int notused);

    // Префіксна форма унарного оператора зміни знаку "-"
    kooClass operator-();
    void Show(char *s);
};
// Перевизначення бінарного оператора множення "*".
kooClass kooClass::operator*(kooClass obj)
{
    kooClass tmp; // Створення тимчасового об'єкта
    tmp.x = x * obj.x; // Операції множення цілочисельних значень
    tmp.y = y * obj.y; // зберігають початковий вміст операндів
    tmp.z = z * obj.z;

    return tmp; // Повертає модифікований тимчасовий об'єкт
}
// Перевизначення оператора присвоєння "=".
kooClass kooClass::operator=(kooClass obj)
{
    x = obj.x; // Операції присвоєння цілочисельних значень
    y = obj.y; // зберігають початковий вміст операндів
    z = obj.z;
    // Повернення модифікованого об'єкта операнда, адресованого покажчиком
    return *this;
}
// Перевизначення префіксної форми унарного оператора інкремента "++".
kooClass kooClass::operator++()
{
    x++; // Інкремент координат x, y і z
    y++;
    z++;
    // Повернення модифікованого об'єкта операнда, адресованого покажчиком
    return *this;
}
// Перевизначення постфіксної форми унарного оператора інкремента "++".
kooClass kooClass::operator++(int notused)
{
    kooClass tmp = *this; // Збереження початкового значення об'єкта
    x++; // Інкремент координат x, y і z
    y++;
    z++;
    return tmp; // Повернення початкового значення об'єкта
}
// Перевизначення префіксної форми унарного оператора зміни знаку "-".
kooClass kooClass::operator-()
{
    x=-x; // Зміна знаку координат x, y і z
    y=-y;
    z=-z;
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

    ObjC = ObjA * ObjB; // Множення об'єктів ObjA і ObjB
    ObjC.Show("C=A*B");

    ObjC = ObjA * ObjB * ObjC; // Множинне множення об'єктів
    ObjC.Show("C=A*B*C");

    ObjC = ObjB = ObjA; // Множинне присвоєння об'єктів
    ObjC.Show("C=B");
    ObjB.Show("B=A");
    ++ObjC; // Префіксна форма операції інкремента
    ObjC.Show("++C");
    ObjC++; // Постфіксна форма операції інкремента
    ObjC.Show("C++");
    ObjA = ++ObjC; // Об'єкт ObjA набуває значення об'єкта ObjC після його інкрементування.
    ObjA.Show("A = ++C"); // Тепер об'єкти ObjA і ObjC мають однакові значення.
    ObjC.Show("C");
    ObjA = ObjC++; // Об'єкт ObjA набуває значення об'єкта ObjC до його інкрементування.
    ObjA.Show("A=C++"); // Тепер об'єкти ObjA і ObjC мають різні значення.
    ObjC.Show("C");
    -ObjC; // Префіксна форма операції зміни знаку
    ObjC.Show("-C");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

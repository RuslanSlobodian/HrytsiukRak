/*
 * Код програми 4.5. Демонстрація механізму перевизначення бінарних операторів
 * множення "*" і ділення "/" з використанням функцій "друзів" класу
 */

#include <cstdlib>
#include <iostream>

using namespace std;            // Використання стандартного простору імен

class KooClass {                // Оголошення класового типу
    int x;                      //
    int y;                      // Тривимірні координати
    int z;                      //
public:
    KooClass() {x = y = z = 0; }
    KooClass(int x, int y, int z) : x(x), y(y), z(z) { }
    friend KooClass operator*(KooClass object, int c);
    friend KooClass operator*(int c, KooClass object);
    friend KooClass operator/(KooClass object, int c);
    friend KooClass operator/(int c, KooClass object);
    void show(char *s);
};

// Операторна "дружня" функція класу
// Перевизначення бінарного оператора множення "*"
KooClass operator*(KooClass object, int c) {
    KooClass tmp;               // Створення тимчасового об'єкта
    tmp.x = object.x * c;
    tmp.y = object.y * c;
    tmp.z = object.z * c;
    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

// Операторна "дружня" функція класу
// Перевизначення бінарного оператора множення "*"
KooClass operator*(int c, KooClass object) {
    KooClass tmp;               // Створення тимчасового об'єкта
    tmp.x = c * object.x;
    tmp.y = c * object.y;
    tmp.z = c * object.z;
    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

// Перевизначення бінарного оператора ділення "/"
KooClass operator/(KooClass object, int c) {
    KooClass tmp;               // Створення тимчасового об'єкта
    tmp.x = object.x / c;
    tmp.y = object.y / c;
    tmp.z = object.z / c;
    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

// Перевизначення бінарного оператора ділення "/"
KooClass operator/(int c, KooClass object) {
    KooClass tmp;               // Створення тимчасового об'єкта
    tmp.x = c / object.x;
    tmp.y = c / object.y;
    tmp.z = c / object.z;
    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

// Відображення тривимірних координат x, y, z
void KooClass::show(char *s) {
    cout << "Координати об'єкта <" << s << ">: ";
    cout << "\t\tx= " << x << ", y= " << y << ", z= " << z << endl;
}

int main() {
    KooClass objectA(1, 2, 3);
    KooClass objectB(10, 10, 10);
    KooClass objectC;
    int a = 10;
    int b = 5;
    objectA.show("A");
    objectB.show("B");
    objectC = objectA * a;      // Множення об'єкта objectA на число a
    objectC.show("C = A * a");
    objectC = a * objectA;      // Множення числа a на об'єкт objectA
    objectC.show("C = a * A");
    objectC = objectB / b;      // Ділення об'єкта objectB на число b
    objectC.show("C = B * b");
    objectC = a / objectB;      // Ділення числа a на об'єкт objectB
    objectC.show("C = a / B");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

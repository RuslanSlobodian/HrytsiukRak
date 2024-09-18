// Код програми 4.5. Демонстрація механізму перевизначення бінарних операторів "*" і "/" з використанням дружніх функцій

#include <cstdlib>
#include <iostream>

using namespace std;

class Coordinates {             // Оголошення класового типу
    int x;                      //
    int y;                      // Тривимірні координати
    int z;                      //
public:
    Coordinates() { x = y = z = 0; }

    Coordinates(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    friend Coordinates operator*(Coordinates lhs, int number);

    friend Coordinates operator*(int number, Coordinates rhs);

    friend Coordinates operator/(Coordinates lhs, int number);

    friend Coordinates operator/(int number, Coordinates obi);

    int getX() { return x; }

    int getY() { return y; }

    int getZ() { return z; }

    void show(string str);
};

// Операторна "дружня" функція класу
// Перевизначення бінарного оператора множення "*"
Coordinates operator*(Coordinates lhs, int number) {
    Coordinates tmp;            // Створення тимчасового об'єкта
    tmp.x = lhs.x * number;
    tmp.y = lhs.y * number;
    tmp.z = lhs.z * number;
    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

// Операторна "дружня" функція класу.
// Перевизначення бінарного оператора множення "*"
Coordinates operator*(int number, Coordinates rhs) {   // rhs - right-hand side
    Coordinates tmp(number * rhs.getX(), number * rhs.getY(), number * rhs.getZ()); // Створення тимчасового об'єкта
//    tmp.x = number * rhs.x;
//    tmp.y = number * rhs.y;
//    tmp.z = number * rhs.z;
    return tmp; // Повертає модифікований тимчасовий об'єкт
}

// Перевизначення бінарного оператора ділення "/"
Coordinates operator/(Coordinates lhs, int number) {    // lhs - left-hand side
    Coordinates tmp; // Створення тимчасового об'єкта
    tmp.x = lhs.x / number;
    tmp.y = lhs.y / number;
    tmp.z = lhs.z / number;
    return tmp; // Повертає модифікований тимчасовий об'єкт
}

// Перевизначення бінарного оператора ділення "/"
Coordinates operator/(int number, Coordinates obi) {
    Coordinates tmp; // Створення тимчасового об'єкта
    tmp.x = number / obi.x;
    tmp.y = number / obi.y;
    tmp.z = number / obi.z;
    return tmp; // Повертає модифікований тимчасовий об'єкт
}

// Відображення тривимірних координат x, y, z.
void Coordinates::show(string str) {
    cout << "Координати об'єкта <" << str << ">: ";
    cout << "\t\tx= " << x << ", y= " << y << ", z= " << z << endl;
}

int main() {
    system("chcp 65001");
    Coordinates objectA(1, 2, 3), objectB(10, 10, 10), objectC;
    int a = 10, b = 5;
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

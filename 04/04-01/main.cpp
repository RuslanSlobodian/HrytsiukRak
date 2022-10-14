/*
 * Код програми 4.1. Демонстрація механізму перевизначення бінарних операторів
 * додавання "+" та присвоєння "=" за допомогою методів
 */

#include <cstdlib>
#include <iostream>

using namespace std;            // Використання стандартного простору імен

class KooClass {                // Оголошення класового типу
    int x;                      //
    int y;                      // Тривимірні координати
    int z;                      //
public:
    KooClass() { x = y = z = 0; }
    KooClass(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    KooClass operator+(KooClass object); // Операнд object передається неявно
    KooClass operator=(KooClass object); // Операнд object передається неявно
    void show(char *s);
};

// Перевизначення бінарного оператора додавання "+"
KooClass KooClass::operator+(KooClass object) {
    KooClass tmp;               // Створення тимчасового об'єкта
    tmp.x = x + object.x;          // Операції додавання цілочисельних значень
    tmp.y = y + object.y;          // зберігають початковий вміст операндів
    tmp.z = z + object.z;

    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

// Перевизначення оператора присвоєння "="
KooClass KooClass::operator=(KooClass object) {
    this->x = object.x;            // Операції присвоєння цілочисельних значень
    y = object.y;                  // зберігають початковий вміст операндів
    z = object.z;

    // Повернення модифікованого об'єкта операнда, адресованого покажчиком
    return *this;
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

    objectA.show("A");
    objectB.show("B");

    objectC = objectA + objectB;            // Додавання об'єктів objectA і objectB
    objectC.show("C = A + B");
    objectC = objectA + objectB + objectC;  // Множинне додавання об'єктів
    objectC.show("C = A + B + C");
    objectC = objectB = objectA;            // Множинне присвоєння об'єктів
    objectB.show("B = A");
    objectC.show("C = B");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

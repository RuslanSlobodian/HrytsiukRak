// Код програми 4.4. Демонстрація механізму перевизначення бінарного оператора "+" за допомогою "дружньої" функції класу

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

    Coordinates(const Coordinates &source) {
        this->x = source.x;
        this->y = source.y;
        this->z = source.z;
    }

    friend Coordinates operator+(Coordinates lhs, Coordinates rhs);

    Coordinates operator=(Coordinates rhs); // Операнд rhs передається неявно
    void show(string str);
};

// Операторна "дружня" функція класу
// Перевизначення бінарного оператора додавання "+"
Coordinates operator+(Coordinates lhs, Coordinates rhs) {   // lhs - left-hand side, rhs - right-hand side
    Coordinates tmp;            // Створення тимчасового об'єкта
    tmp.x = lhs.x + rhs.x;
    tmp.y = lhs.y + rhs.y;
    tmp.z = lhs.z + rhs.z;
    return tmp;                 // Повертає тимчасовий об'єкт
}

// Перевизначення оператора присвоєння "="
Coordinates Coordinates::operator=(Coordinates rhs) {   // rhs - right-hand side
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    // Повернення модифікованого об'єкта операнда, адресованого вказівником this (lhs)
    return *this;
}

// Відображення тривимірних координат x, y, z
void Coordinates::show(string str) {
    cout << "Координати об'єкта <" << str << ">: ";
    cout << "\t\tx= " << x << ", y= " << y << ", z= " << z << endl;
}

int main() {
    system("chcp 65001");
    Coordinates objectA(1, 2, 3), objectB(10, 10, 10), objectC;
    objectA.show("A");
    objectB.show("B");
    objectC = objectA + objectB;// Додавання об'єктів objectA і objectB
    objectC.show("C = A + B");
    objectC = objectA + objectB + objectC; // Множинне додавання об'єктів
    objectC.show("C = A + B + C");
    objectC = objectB = objectA;// Множинне присвоєння об'єктів
    objectC.show("C = B");
    objectB.show("B = A");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

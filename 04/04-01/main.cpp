// Код програми 4.1. Демонстрація механізму перевизначення бінарних операторів додавання "+" та присвоєння "=" за допомогою методів

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

    Coordinates(const Coordinates &source){
        this->x = source.x;
        this->y = source.y;
        this->z = source.z;
    }

    Coordinates operator+(Coordinates object); // Операнд object передається неявно
    Coordinates operator=(Coordinates object); // Операнд object передається неявно
    void show(string str);
};

// Перевизначення бінарного оператора додавання "+"
Coordinates Coordinates::operator+(Coordinates object) {
    Coordinates tmp;            // Створення тимчасового об'єкта
    tmp.x = x + object.x;       // Операції додавання цілочисельних значень
    tmp.y = y + object.y;       // зберігають початковий вміст операндів
    tmp.z = z + object.z;

    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

// Перевизначення оператора присвоєння "="
Coordinates Coordinates::operator=(Coordinates object) {
    this->x = object.x;         // Операції присвоєння цілочисельних значень
    y = object.y;               // зберігають початковий вміст операндів
    z = object.z;

    // Повернення модифікованого об'єкта операнда, адресованого покажчиком
    return *this;
}

// Відображення тривимірних координат x, y, z
void Coordinates::show(string str) {
    cout << "Координати об'єкта <" << str << ">: ";
    cout << "\t\tx= " << x << ", y= " << y << ", z= " << z << endl;
}

int main() {
    system("chcp 65001");
    Coordinates objectA(1, 2, 3);
    Coordinates objectB(10, 10, 10);
    Coordinates objectC;

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

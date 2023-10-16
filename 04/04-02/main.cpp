// Код програми 4.2. Демонстрація механізму перевизначення префіксної форми унарного оператора інкремента "++"

#include <cstdlib>
#include <iostream>

using namespace std;

class Coordinates {             // Оголошення класового типу
    int x;
    int y;
    int z;
public:
    Coordinates() { x = y = z = 0; }

    Coordinates(int c, int d, int f) {
        x = c;
        y = d;
        z = f;
    }

    Coordinates(const Coordinates &source){
        this->x = source.x;
        this->y = source.y;
        this->z = source.z;
    }

    Coordinates operator-(Coordinates obj); // Операнд obj передається неявно
    Coordinates operator=(Coordinates obj); // Операнд obj передається неявно
    Coordinates operator++();   // Префіксна форма оператора інкремента "++"
    void show(string str);
};

// Перевизначення бінарного оператора віднімання "-".
Coordinates Coordinates::operator-(Coordinates obj) {
    Coordinates tmp;            // Створення тимчасового об'єкта
    tmp.x = this->x - obj.x;    // Операції віднімання цілочисельних значень
    tmp.y = this->y - obj.y;    // зберігають початковий вміст операндів.
    tmp.z = this->z - obj.z;

    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

// Перевизначення оператора присвоєння "=".
Coordinates Coordinates::operator=(Coordinates obj) {
    x = obj.x;                  // Операції присвоєння цілочисельних значень
    y = obj.y;                  // зберігають початковий вміст операндів
    z = obj.z;
    return *this;
}

// Повернення модифікованого об'єкта операнда, адресованого покажчиком
// Перевизначення префіксної форми унарного оператора інкремента "++".
Coordinates Coordinates::operator++() {
    x++;
    y++;                        // Інкремент координат x, y і z
    z++;
    // Повернення модифікованого об'єкта операнда, адресованого покажчиком
    return *this;
}

// Відображення тривимірних координат x, y, z.
void Coordinates::show(string str) {
    cout << "Координати об'єкта <" << str << ">: ";
    cout << "\t\tx= " << x << ", y= " << y << ", z= " << z << endl;
}

int main() {
    system("chcp 65001");
    Coordinates objectA(1, 2, 3), objectB(10, 10, 10), objectC;

    objectA.show("A");
    objectB.show("B");

    objectC = objectA - objectB;// Віднімання об'єктів objectA і objectB
    objectC.show("C = A - B");

    objectC = objectA - objectB - objectC; // Множинне віднімання об'єктів
    objectC.show("C = A - B - C");
    objectC = objectB = objectA;// Множинне присвоєння об'єктів
    objectB.show("B = A");
    objectC.show("C = B");

    ++objectC;                  // Префіксний інкремент об'єкта objectC
    objectC.show("++C");
    objectA = ++objectC;        // Префіксний інкремент об'єкта objectC
    objectC.show("C");
    objectA.show("A = ++C");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

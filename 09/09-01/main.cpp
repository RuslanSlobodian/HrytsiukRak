// Код програми 9.1. Демонстрація механізму реалізації перевизначеного оператора виведення даних

#include <iostream>
#include <cstdlib>

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

    int getX() { return x; }

    int getY() { return y; }

    int getZ() { return z; }
};

// Відображення тривимірних координат x, y, z
// Перевизначений оператор виведення даних для класу Coordinates
ostream& operator<<(ostream& stream, Coordinates object) {
    stream << object.getX() << ", ";
    stream << object.getY() << ", ";
    stream << object.getZ() << endl;

    return stream;              // Повертає посилання на параметр stream
}

int main() {
    Coordinates objectA(1, 2, 3);
    Coordinates objectB(3, 4, 5);
    Coordinates objectC(5, 6, 7);

    // Перевизначений оператор виведення даних
    cout << objectA << objectB << objectC;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Код програми 9.2. Демонстрація механізму використання дружніх функцій класу для перевизначення оператора виведення даних

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

    friend ostream& operator<<(ostream& stream, Coordinates object);
};

// Відображення тривимірних координат x, y, z
// Перевизначений оператор виведення даних для класу Coordinates
ostream& operator<<(ostream& stream, Coordinates object) {
    stream << object.x << ", ";
    stream << object.y << ", ";
    stream << object.z << endl;

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

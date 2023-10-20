// Код програми 9.3. Демонстрація механізму перевизначення операторів введення/виведення потокової інформації

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

    friend istream& operator>>(istream& stream, Coordinates& object);
};

// Відображення тривимірних координат x, y, z
// Перевизначений оператор виведення даних для класу Coordinates
ostream& operator<<(ostream& stream, Coordinates object) {
    stream << object.x << ", ";
    stream << object.y << ", ";
    stream << object.z << endl;

    return stream;              // Повертає посилання на параметр stream
}

// Прийняття тривимірних координат x, y, z
// Перевизначений оператор введення даних для класу kooClass
istream& operator>>(istream& stream, Coordinates& object) {
    cout << "Введiть координати x, y i z: ";

    // Перевизначений оператор введення даних
    stream >> object.x >> object.y >> object.z;
    return stream;              // Повертає посилання на параметр stream
}

int main() {
    system("chcp 65001");
    Coordinates objectA(1, 2, 3);

    cout << objectA;            // Перевизначений оператор виведення даних

    cin >> objectA;             // Перевизначений оператор введення даних
    cout << objectA;            // Перевизначений оператор виведення даних

    //system("PAUSE");
    return EXIT_SUCCESS;
}

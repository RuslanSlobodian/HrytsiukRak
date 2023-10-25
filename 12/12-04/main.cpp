// Код програми 12.4. Демонстрація механізму зберігання у векторі об'єктів класу

#include <iostream>
#include <cstdlib>
#include <vector>                // Для роботи з контейнерним класом "Вектор"

using namespace std;

class Coordinates {
    int x;
    int y;
    int z;
public:
    Coordinates() { x = y = z = 0; }

    Coordinates(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // Повертає модифікований об'єкт, адресований вказівником
    Coordinates& operator+(int a) {
        x += a;
        y += a;
        z += a;
        return *this;
    }

    friend ostream& operator<<(ostream& stream, const Coordinates& objectA);

    friend bool operator<(const Coordinates& objectA, const Coordinates& objectB);

    friend bool operator==(const Coordinates& objectA, const Coordinates& objectB);
};

// Відображаємо координати x, y, z за допомогою оператора виведення для класу Coordinates
ostream& operator<<(ostream& stream, const Coordinates& objectA) {
    stream << "x= " << objectA.x << ", ";
    stream << "y= " << objectA.y << ", ";
    stream << "z= " << objectA.z << endl;
    return stream;              // Повертає посилання на параметр stream
}

bool operator<(const Coordinates& objectA, const Coordinates& objectB) {
    return (objectA.x + objectA.y + objectA.z) < (objectB.x + objectB.y + objectB.z);
}

bool operator==(const Coordinates& objectA, const Coordinates& objectB) {
    return (objectA.x + objectA.y + objectA.z) == (objectB.x + objectB.y + objectB.z);
}

int main() {
    vector<Coordinates> coordinatesVector;  // Побудова вектора об'єктів нульової довжини

    // Додаємо у вектор об'єкти
    for (int i = 0; i < 10; i++)
        coordinatesVector.push_back(Coordinates(i, i + 2, i - 3));

    cout << "Вiдображаємо вмiст початкового вектора" << endl;
    for (int i = 0; i < coordinatesVector.size(); i++)
        cout << i << " ==> " << coordinatesVector[i];

    cout << endl;
    // Модифікуємо об'єкти у векторі

    for (int i = 0; i < coordinatesVector.size(); i++)
        coordinatesVector[i] = coordinatesVector[i] + 10;

    cout << "Вiдображаємо вмiст модифiкованого вектора" << endl;
    for (int i = 0; i < coordinatesVector.size(); i++)
        cout << i << " ==> " << coordinatesVector[i];

    //system("PAUSE");
    return EXIT_SUCCESS;
}

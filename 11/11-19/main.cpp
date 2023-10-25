// Код програми 11.19. Демонстрація механізму використання функції перетворення типів

#include <iostream>
#include <cstdlib>

using namespace std;

class Coordinates {             // Оголошення класового типу
    int x;                      //
    int y;                      // Тривимірні координати
    int z;                      //
public:
    Coordinates(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Coordinates operator+(const Coordinates& obj) const;

    friend ostream& operator<<(ostream& stream, const Coordinates& obj);

    operator int() { return x * y * z; }
};

// Відображення тривимірних координат x, y, z - функція виведення даних для класу Coordinates
ostream& operator<<(ostream& stream, const Coordinates& obj) {
    stream << obj.x << ", ";
    stream << obj.y << ", ";
    stream << obj.z << endl;
    return stream;              // Повертає посилання на параметр stream
}

Coordinates Coordinates::operator+(const Coordinates& obj) const {
    Coordinates tmp(0, 0, 0);
    tmp.x = x + obj.x;
    tmp.y = y + obj.y;
    tmp.z = z + obj.z;
    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

int main() {
    Coordinates objectA(1, 2, 3), objectB(2, 3, 4);
    cout << objectA << objectB;
    cout << objectB + 100;      // Відображає число 124, оскільки тут здійснюється
                                // перетворення об'єкта класу у значення типу int
    cout << endl;
    objectA = objectA + objectB;// Додавання двох об'єктів класу Coordinates
                                // виконується без перетворення типу
    cout << objectA;            // Відображає координати 3, 5, 7

    //system("PAUSE");
    return EXIT_SUCCESS;
}

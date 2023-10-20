// Код програми 9.21. Демонстрація механізму використання перевизначеного
// оператора введення-виведення даних для запису об'єктів класу у файл

#include <iostream>
#include <cstdlib>
#include <fstream>              // Для роботи з файлами

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
    system("chcp 65001");
    Coordinates objectA(1, 2, 3), objectB(3, 4, 5), objectC(5, 6, 7);
    ofstream outStream("Coordinates.txt");
    if (!outStream) {
        cout << "Не вдається вiдкрити файл.";
        return 1;
    }
    // Перевизначений оператор виведення даних
    outStream << objectA << objectB << objectC;

    outStream.close();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

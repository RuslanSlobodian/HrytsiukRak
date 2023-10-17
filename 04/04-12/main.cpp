// Код програми 4.12. Демонстрація механізму перевизначення оператора виклику функцій "()"

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

    Coordinates(const Coordinates &source){
        this->x = source.x;
        this->y = source.y;
        this->z = source.z;
    }

    Coordinates operator()(int a, int b, int c);

    void show(string str);
};

// Перевизначення оператора виклику функцій "()"
Coordinates Coordinates::operator()(int a, int b, int c) {
    Coordinates tmp; // Створення тимчасового об'єкта
    tmp.x = x + a;
    tmp.y = y + b;
    tmp.z = z + c;
    return tmp; // Повертає модифікований тимчасовий об'єкт
}

// Відображення тривимірних координат x, y, z
void Coordinates::show(string str) {
    cout << "Координати об'єкта <" << str << ">: ";
    cout << "\t\tx= " << x << ", y= " << y << ", z= " << z << endl;
}

int main() {
    system("chcp 65001");
    Coordinates objectA(1, 2, 3), objectB;
    objectB = objectA(10, 11, 12); // Виклик функції operator()
    objectA.show("A");
    objectB.show("B");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

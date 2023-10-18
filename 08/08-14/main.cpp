// Код програми 8.14. Демонстрацiя механiзму перевизначення операторiв new i delete

#include <iostream>
#include <cstdlib>

using namespace std;

class Coordinates {             // Оголошення класового типу
    int x;
    int y;
    int z;

public:
    Coordinates() { x = y = z = 0; }

    Coordinates(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
        cout << "Створення об'єкта " << x << ", ";
        cout << y << ", " << z << endl;
    }

    Coordinates(const Coordinates& source) {
        this->x = source.x;
        this->y = source.y;
        this->z = source.z;
    }

    ~Coordinates() { cout << "Руйнування об'єкта" << endl; }

    void* operator new(size_t size);

    void* operator new[](size_t size);

    void operator delete(void* p);

    void operator delete[](void* p);

    void show(string str);
};

// Перевизначення оператора new для класу Coordinates
void* Coordinates::operator new(size_t size) {
    void* p;
    cout << "Видiлення областi пам'ятi для об'єкта класу Coordinates" << endl;
    p = malloc(size);

    // Генерування винятку у разi невдалого видiлення областi пам'ятi
    if (!p) {
        bad_alloc ba;
        throw ba;
    }
    return p;
}

// Перевизначення оператора new для масиву об'єктiв типу Coordinates
void* Coordinates::operator new[](size_t size) {
    void* p;

    cout << "Видiлення областi пам'ятi для масиву oб'єктiв класу Coordinates" << endl;
    // Генерування винятку при невдачi
    p = malloc(size);
    if (!p) {
        bad_alloc ba;
        throw ba;
    }
    return p;
}

// Перевизначення оператора delete для класу Coordinates
void Coordinates::operator delete(void* p) {
    cout << "Видалення об'єкта класу Coordinates" << endl;
    free(p);
}

// Перевизначення оператора delete для масиву об'єктiв типу Coordinates
void Coordinates::operator delete[](void* p) {
    cout << "Видалення масиву об'єктiв типу Coordinates" << endl;
    free(p);
}

// Вiдображення тривимiрних координат x, y, z
void Coordinates::show(string str) {
    cout << "Координати об'єкта <" << str << ">: ";
    cout << "\t\tx= " << x << ", y= " << y << ", z= " << z << endl;
}

int main() {
    system("chcp 65001");
    Coordinates* p1, * p2;
    try {
        p1 = new Coordinates[3]; // Видiлення областi пам'ятi для масиву об'єктів класу Coordinates
        p2 = new Coordinates(5, 6, 7); // Видiлення областi пам'ятi для об'єкта
    }
    catch (bad_alloc ba) {
        cout << "Помилка пiд час видiлення областi пам'ятi" << endl;
        return 1;
    }
    p1[1].show("Базовий клас: ");
    p2->show("Базовий клас: ");

    delete[] p1;                // Видалення масиву
    delete p2;                  // Видалення об'єкта

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Код програми 4.3. Демонстрація механізму перевизначення унарного оператора інкремента "++" з використанням його префіксної та пост-фіксної форм

#include <cstdlib>
#include <iostream>

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
    }

    Coordinates(const Coordinates& source) {
        this->x = source.x;
        this->y = source.y;
        this->z = source.z;
    }

    Coordinates operator*(Coordinates rhs); // Операнд rhs передається неявно
    Coordinates operator=(Coordinates rhs); // Операнд rhs передається неявно
    Coordinates operator++();   // Префіксна форма оператора інкремента "++"

    // Постфіксна форма оператора інкремента "++"
    Coordinates operator++(int notUsed);

    // Префіксна форма унарного оператора зміни знаку "-"
    Coordinates operator-();

    void show(string str);
};

// Перевизначення бінарного оператора множення "*"
Coordinates Coordinates::operator*(Coordinates rhs) {
    Coordinates tmp; // Створення тимчасового об'єкта
    tmp.x = x * rhs.x; // Операції множення цілочисельних значень
    tmp.y = y * rhs.y; // зберігають початковий вміст операндів
    tmp.z = z * rhs.z;

    return tmp; // Повертає модифікований тимчасовий об'єкт
}

// Перевизначення оператора присвоєння "="
Coordinates Coordinates::operator=(Coordinates rhs) {
    x = rhs.x; // Операції присвоєння цілочисельних значень
    y = rhs.y; // зберігають початковий вміст операндів
    z = rhs.z;
    // Повернення модифікованого об'єкта операнда, адресованого вказівником
    return *this;
}

// Перевизначення префіксної форми унарного оператора інкремента "++"
Coordinates Coordinates::operator++() {
    x++; // Інкремент координат x, y і z
    y++;
    z++;
    // Повернення модифікованого об'єкта операнда, адресованого вказівником
    return *this;
}

// Перевизначення постфіксної форми унарного оператора інкремента "++"
Coordinates Coordinates::operator++(int notUsed) {
    Coordinates tmp = *this; // Збереження початкового значення об'єкта
    x++; // Інкремент координат x, y і z
    y++;
    z++;
    return tmp; // Повернення початкового значення об'єкта
}

// Перевизначення префіксної форми унарного оператора зміни знаку "-"
Coordinates Coordinates::operator-() {
    x = -x; // Зміна знаку координат x, y і z
    y = -y;
    z = -z;
    // Повернення модифікованого об'єкта операнда, адресованого вказівником
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

    objectC = objectA * objectB;// Множення об'єктів objectA і objectB
    objectC.show("C = A * B");

    objectC = objectA * objectB * objectC; // Множинне множення об'єктів
    objectC.show("C = A * B * C");

    objectC = objectB = objectA; // Множинне присвоєння об'єктів
    objectC.show("C = B");
    objectB.show("B = A");
    ++objectC;                  // Префіксна форма операції інкремента
    objectC.show("++C");
    objectC++;                  // Постфіксна форма операції інкремента
    objectC.show("C++");
    objectA = ++objectC;        // Об'єкт objectA набуває значення об'єкта objectC після його інкрементування
    objectA.show("A = ++C");    // Тепер об'єкти objectA і objectC мають однакові значення
    objectC.show("C");
    objectA = objectC++;        // Об'єкт objectA набуває значення об'єкта objectC до його інкрементування
    objectA.show("A = C++");    // Тепер об'єкти objectA і objectC мають різні значення
    objectC.show("C");
    -objectC;                   // Префіксна форма операції зміни знаку
    objectC.show("-C");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

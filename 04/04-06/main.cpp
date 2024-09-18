// Код програми 4.6. Демонстрація механізму використання "дружньої" функції класу
// для перевизначення префіксної та постфіксної форми операторів інкремента

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

    Coordinates(const Coordinates& source) {
        this->x = source.x;
        this->y = source.y;
        this->z = source.z;
    }

    friend Coordinates operator*(Coordinates obi, Coordinates obj);

    Coordinates operator=(Coordinates obj);

    // Ці функції для перевизначення оператора інкремента "++"
    // використовують посилальні параметри
    friend Coordinates operator++(Coordinates& obi);

    friend Coordinates operator++(Coordinates& obi, int notUsed);

    void show(string str);
};

// Операторна "дружня" функція класу
Coordinates operator*(Coordinates obi, Coordinates obj) {
    Coordinates tmp;            // Створення тимчасового об'єкта
    tmp.x = obi.x * obj.x;
    tmp.y = obi.y * obj.y;
    tmp.z = obi.z * obj.z;
    return tmp;                 // По   вертає модифікований тимчасовий об'єкт
}

// Перевизначення оператора присвоєння "="
Coordinates Coordinates::operator=(Coordinates obj) {
    x = obj.x;
    y = obj.y;
    z = obj.z;
    // Повернення модифікованого об'єкта операнда, адресованого вказівником
    return *this;
}

// Перевизначення префіксної форми унарного оператора інкремента "++" з використанням
// "дружньої" функції класу. Для цього необхідне використання посилального параметра
Coordinates operator++(Coordinates& obi) {
    obi.x++;
    obi.y++;
    obi.z++;
    return obi;
}

// Перевизначення постфіксної форми унарного оператора інкремента "++" з використанням
// "дружньої" функції класу. Для цього необхідне використання посилального параметра
Coordinates operator++(Coordinates& obi, int notUsed) {
    Coordinates tmp = obi;
    obi.x++;
    obi.y++;
    obi.z++;
    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

// Відображення тривимірних координат x, y, z
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
    objectC.show("C=A*B");
    objectC = objectA * objectB * objectC; // Множинне множення об'єктів
    objectC.show("c");
    objectC = objectB = objectA;// Множинне присвоєння об'єктів
    objectC.show("C=B");
    objectB.show("B=A");
    ++objectC;                  // Префіксна форма операції інкремента
    objectC.show("++C");
    objectC++;                  // Постфіксна версія інкремента
    objectC.show("C++");
    objectA = ++objectC;        // Об'єкт objectA набуває значення об'єкта objectC після інкрементування
    objectA.show("A = ++C");    // У цьому випадку об'єкти objectA і objectC
    objectC.show("C");          // мають однакові значення координат
    objectA = objectC++;        // Об'єкт objectA набуває значення об'єкта objectC до інкрементування
    objectA.show("A=C++");      // У цьому випадку об'єкти objectA і objectC
    objectC.show("C");          // мають різні значення координат

    //system("PAUSE");
    return EXIT_SUCCESS;
}

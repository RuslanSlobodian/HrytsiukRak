// Код програми 4.4. Демонстрація механізму перевизначення бінарного оператора додавання "+" за допомогою "дружньої" функції класу

#include <cstdlib>
#include <iostream>

using namespace std;            // Використання стандартного простору імен

class KooClass {                // Оголошення класового типу
    int x;                      //
    int y;                      // Тривимірні координати
    int z;                      //
public:
    KooClass() {x = y = z = 0; }
    KooClass(int x, int y, int z) : x(x), y(y), z(z) { }
    friend KooClass operator+(KooClass objectA, KooClass objectB);
    KooClass operator=(KooClass objectc); // Операнд object передається неявно
    void show(char *s);
};

// Операторна "дружня" функція класу
// Перевизначення бінарного оператора додавання "+"
KooClass operator+(KooClass objectA, KooClass objectB) {
    KooClass tmp; // Створення тимчасового об'єкта
    tmp.x = objectA.x + objectB.x;
    tmp.y = objectA.y + objectB.y;
    tmp.z = objectA.z + objectB.z;
    return tmp; // Повертає модифікований тимчасовий об'єкт
}

// Перевизначення оператора присвоєння "="
KooClass KooClass::operator=(KooClass object) {
    x = object.x;
    y = object.y;
    z = object.z;
    // Повернення модифікованого об'єкта операнда, адресованого вказівником
    return *this;
}

// Відображення тривимірних координат x, y, z
void KooClass::show(char *s) {
    cout << "Координати об'єкта <" << s << ">: ";
    cout << "\t\tx= " << x << ", y= " << y << ", z= " << z << endl;
}

int main() {
    KooClass objectA(1, 2, 3);
    KooClass objectB(10, 10, 10);
    KooClass objectC;
    objectA.show("A");
    objectB.show("B");
    objectC = objectA + objectB;            // Додавання об'єктів objectA і objectB
    objectC.show("C = A + B");
    objectC = objectA + objectB + objectC;  // Множинне додавання об'єктів
    objectC.show("C = A + B + C");
    objectC = objectB = objectA;            // Множинне присвоєння об'єктів
    objectC.show("C = B");
    objectB.show("B = A");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

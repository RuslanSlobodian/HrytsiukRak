// Код програми 4.3. Демонстрація механізму перевизначення унарного оператора інкремента "++" з використанням його префіксної та пост-фіксної форм

#include <cstdlib>
#include <iostream>

using namespace std;            // Використання стандартного простору імен

class KooClass {                // Оголошення класового типу
    int x;                      //
    int y;                      // Тривимірні координати
    int z;                      //
public:
    KooClass() { x = y = z = 0; }
    KooClass(int x, int y, int z) : x(x), y(y), z(z) { }
    KooClass operator*(KooClass object); // Операнд object передається неявно
    KooClass operator=(KooClass object); // Операнд object передається неявно
    KooClass operator++();      // Префіксна форма оператора інкремента "++"

    // Постфіксна форма оператора інкремента "++"
    KooClass operator++(int notused);

    // Префіксна форма унарного оператора зміни знаку "-"
    KooClass operator-();
    void show(char *s);
};

// Перевизначення бінарного оператора множення "*"
KooClass KooClass::operator*(KooClass object) {
    KooClass tmp; // Створення тимчасового об'єкта
    tmp.x = x * object.x; // Операції множення цілочисельних значень
    tmp.y = y * object.y; // зберігають початковий вміст операндів
    tmp.z = z * object.z;

    return tmp; // Повертає модифікований тимчасовий об'єкт
}

// Перевизначення оператора присвоєння "="
KooClass KooClass::operator=(KooClass object) {
    x = object.x; // Операції присвоєння цілочисельних значень
    y = object.y; // зберігають початковий вміст операндів
    z = object.z;
    // Повернення модифікованого об'єкта операнда, адресованого покажчиком
    return *this;
}

// Перевизначення префіксної форми унарного оператора інкремента "++"
KooClass KooClass::operator++() {
    x++; // Інкремент координат x, y і z
    y++;
    z++;
    // Повернення модифікованого об'єкта операнда, адресованого вказівником
    return *this;
}

// Перевизначення постфіксної форми унарного оператора інкремента "++"
KooClass KooClass::operator++(int notused) {
    KooClass tmp = *this; // Збереження початкового значення об'єкта
    x++; // Інкремент координат x, y і z
    y++;
    z++;
    return tmp; // Повернення початкового значення об'єкта
}

// Перевизначення префіксної форми унарного оператора зміни знаку "-"
KooClass KooClass::operator-() {
    x=-x; // Зміна знаку координат x, y і z
    y=-y;
    z=-z;
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

    objectC = objectA * objectB;// Множення об'єктів ObjA і objectB
    objectC.show("C = A * B");

    objectC = objectA * objectB * objectC; // Множинне множення об'єктів
    objectC.show("C = A * B * C");

    objectC = objectB = objectA;// Множинне присвоєння об'єктів
    objectC.show("C = B");
    objectB.show("B = A");

    ++objectC;                  // Префіксна форма операції інкремента
    objectC.show("++C");
    objectC++;                  // Постфіксна форма операції інкремента
    objectC.show("C++");

    // Об'єкт ObjA набуває значення об'єкта objectC після його інкрементування
    objectA = ++objectC;
    // Тепер об'єкти objectA і objectC мають однакові значення
    objectA.show("A = ++C");
    objectC.show("C");

    // Об'єкт objectA набуває значення об'єкта objectC до його інкрементування
    objectA = objectC++;
    // Тепер об'єкти objectA і objectC мають різні значення
    objectA.show("A = C++");
    objectC.show("C");
    -objectC; // Префіксна форма операції зміни знаку
    objectC.show("-C");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

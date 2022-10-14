/*
 * Код програми 4.6. Демонстрація механізму використання "дружньої" функції класу
 * для перевизначення префіксної та постфіксної форми операторів інкремента
 */

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class KooClass {                // Оголошення класового типу
    int x;                      //
    int y;                      // Тривимірні координати
    int z;                      //
public:
    KooClass() {x = y = z = 0; }
    KooClass(int x, int y, int z) : x(x), y(y), z(z) { }
    friend KooClass operator*(KooClass objectA, KooClass objectB);
    KooClass operator=(KooClass object);

    // Ці функції для перевизначення оператора інкремента "++"
    // використовують посилальні параметри
    friend KooClass operator++(KooClass &object);
    friend KooClass operator++(KooClass &object, int notused);
    void show(char *s);
};

// Операторна "дружня" функція класу
KooClass operator*(KooClass objectA, KooClass objectB) {
    KooClass tmp;               // Створення тимчасового об'єкта
    tmp.x = objectA.x * objectB.x;
    tmp.y = objectA.y * objectB.y;
    tmp.z = objectA.z * objectB.z;
    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

// Перевизначення оператора присвоєння "="
KooClass KooClass::operator=(KooClass object) {
    x = object.x;
    y = object.y;
    z = object.z;
    // Повернення модифікованого об'єкта операнда, адресованого вказівником
    return *this;
}

/* Перевизначення префіксної форми унарного оператора інкремента "++" з використанням
 * "дружньої" функції класу. Для цього необхідне використання посилального параметра
*/
KooClass operator++(KooClass &object) {
    object.x++;
    object.y++;
    object.z++;
    return object;
}

/* Перевизначення постфіксної форми унарного оператора інкремента "++" з використанням
 * "дружньої" функції класу. Для цього необхідне використання посилального параметра
 */
KooClass operator++(KooClass &object, int notused) {
    KooClass tmp = object;
    object.x++;
    object.y++;
    object.z++;
    return tmp;                 // Повертає модифікований тимчасовий об'єкт
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
    objectC = objectA * objectB;            // Множення об'єктів objectA і objectB
    objectC.show("C = A * B");
    objectC = objectA * objectB * objectC;  // Множинне множення об'єктів
    objectC.show("C");
    objectC = objectB = objectA ;           // Множинне присвоєння об'єктів
    objectC.show("C = B");
    objectB.show("B = A");
    ++objectC;                  // Префіксна форма операції інкремента
    objectC.show("++C");
    objectC++;                  // Постфіксна версія інкремента
    objectC.show("C++");
    objectA = ++objectC;        // Об'єкт objectA набуває значення об'єкта objectC після інкрементування
    objectA.show("A = ++C");    // У цьому випадку об'єкти objectA і objectC
    objectC.show("C");          // мають однакові значення координат
    objectA = objectC++;        // Об'єкт objectA набуває значення об'єкта objectC до інкрементування
    objectA.show("A = C++");    // У цьому випадку об'єкти objectA і objectC
    objectC.show("C");          // мають різні значення координат

    //system("PAUSE");
    return EXIT_SUCCESS;
}

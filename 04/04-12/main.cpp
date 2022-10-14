// Код програми 4.12. Демонстрація механізму перевизначення оператора виклику функцій "()"

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class KooClass {                // Оголошення класового типу
    int x;                      //
    int y;                      // Тривимірні координати
    int z;                      //
public:
    KooClass() { x = y = z = 0; }
    KooClass(int x, int y, int z) : x(x), y(y), z(z) { }
    KooClass operator()(int a, int b, int c);
    void show(char *s);
};

// Перевизначення оператора виклику функцій "()"
KooClass KooClass::operator()(int a, int b, int c) {
    KooClass tmp;               // Створення тимчасового об'єкта
    tmp.x = x + a;
    tmp.y = y + b;
    tmp.z = z + c;
    return tmp;                 // Повертає модифікований тимчасовий об'єкт
}

// Відображення тривимірних координат x, y, z
void KooClass::show(char *s) {
    cout << "Координати об'єкта <" << s << ">: ";
    cout << "\t\tx= " << x << ", y= " << y << ", z= " << z << endl;
}

int main() {
    KooClass objectA(1, 2, 3);
    KooClass objectB;
    objectB = objectA(10, 11, 12);    // Виклик функції operator()
    objectA.show("A");
    objectB.show("B");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

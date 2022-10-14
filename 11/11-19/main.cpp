//Код програми 11.19. Демонстрація механізму використання функції перетворення типів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class KooClass { // Оголошення класового типу
    int x, y, z; // Тривимірні координати
public:
    KooClass(int a, int b, int c) {x = a; y = b; z = c; }
    KooClass operator+(KooClass obj);

    friend ostream &operator<<(ostream &stream, KooClass &obj);
    operator int() {return x * y * z; }
};

// Відображення тривимірних координат x, y, z - функція виведення 	даних
// для класу kooClass.
ostream &operator<<(ostream &stream, KooClass &obj)
{
    stream << obj.x << ", ";
    stream << obj.y << ", ";
    stream << obj.z << endl;
    return stream; // Повертає посилання на параметр stream
}
KooClass KooClass::operator+(KooClass obj)
{
    KooClass tmp(0, 0, 0);
    tmp.x = x + obj.x;
    tmp.y = y + obj.y;
    tmp.z = z + obj.z;
    return tmp; // Повертає модифікований тимчасовий об'єкт
}
int main()
{
    KooClass ObjA(1, 2, 3), ObjB(2, 3, 4);
    cout << ObjA << ObjB;
    cout << ObjB+100;	// Відображає число 124, оскільки тут здійснюється
    // перетворення об'єкта класу у значення типу int.
    cout << endl;
    ObjA = ObjA + ObjB; 	// Додавання двох об'єктів класу kooClass
    // виконується без перетворення типу.
    cout << ObjA; 		// Відображає координати 3, 5, 7

    //system("PAUSE");
    return EXIT_SUCCESS;
}

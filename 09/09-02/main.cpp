//Код програми 9.2. Демонстраціямеханізму використанняфункцій-"друзів" класу для перевизначення оператора виведення даних

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class KooClass {		 // Оголошення класового типу
    int x, y, z;			 // Тривимірнікоординати (тепер це private-члени)
public:
    KooClass(int a, int b, int c) { x = a; y = b; z = c; }
    friend ostream &operator<<(ostream &stream, KooClass obj);
};

// Відображення тривимірних координат x, y, z
// Перевизначений оператор виведення даних для класу kooClass
ostream &operator<<(ostream &stream, KooClass obj)
{
    stream << obj.x << ", ";
    stream << obj.y << ", ";
    stream << obj.z << endl;

    return stream; // Повертає посилання на параметр stream
}
int main()
{
    KooClass ObjA(1, 2, 3), ObjB(3, 4, 5), ObjC(5, 6, 7);

    // Перевизначений оператор виведення даних
    cout << ObjA << ObjB << ObjC;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 9.1. Демонстраціямеханізму реалізації перевизначеного оператора виведення даних

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class kooClass { // Оголошення класового типу
public:
    int x, y, z; // Тривимірнікоординати
    kooClass(int a, int b, int c) { x = a; y = b; z = c; }
};

// Відображення тривимірних координат x, y, z
// Перевизначений оператор виведення даних для класу kooClass
ostream &operator<<(ostream &stream, kooClass obj)
{
    stream << obj.x << ", ";
    stream << obj.y << ", ";
    stream << obj.z << endl;

    return stream; // Повертає посилання на параметр stream
}

int main()
{
    kooClass ObjA(1, 2, 3), ObjB(3, 4, 5), ObjC(5, 6, 7);

    // Перевизначений оператор виведення даних
    cout << ObjA << ObjB << ObjC;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

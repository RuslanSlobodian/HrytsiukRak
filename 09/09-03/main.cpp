//Код програми 9.3. Демонстраціямеханізму перевизначення операторів введення/виведення потокової інформації

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class KooClass { // Оголошення класового типу
    int x, y, z; // Тривимірнікоординати
public:
    KooClass(int a, int b, int c) { x = a; y = b; z = c; }
    friend ostream &operator<<(ostream &stream, KooClass obj);
    friend istream &operator>>(istream &stream, KooClass &obj);
};

// Відображення тривимірних координат x, y, z
// Перевизначений оператор виведення даних для класу kooClass
ostream &operator<<(ostream&stream, KooClass obj)
{
    stream << obj.x << ", ";
    stream << obj.y << ", ";
    stream << obj.z << endl;

    return stream; // Повертає посилання на параметр stream
}

// Прийняття тривимірних координат x, y, z
// Перевизначений оператор введення даних для класу kooClass
istream &operator>>(istream&stream, KooClass &obj)
{
    cout << "Введiть координати x, y i z: ";

    // Перевизначений оператор введення даних
    stream >> obj.x >> obj.y >> obj.z;
    return stream; // Повертає посилання на параметр stream
}

int main()
{
    KooClass ObjA(1, 2, 3);

    cout << ObjA;	 // Перевизначений оператор виведення даних

    cin >> ObjA	; // Перевизначений оператор введення даних
    cout << ObjA	; // Перевизначений оператор виведення даних

    //system("PAUSE");
    return EXIT_SUCCESS;
}

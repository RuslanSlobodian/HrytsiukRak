//Код програми 9.21. Демонстрація механізму використання перевизначеного
//оператора введення-виведення даних для запису об'єктів класу у файл

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <fstream>			// Для роботи з файлами

using namespace std; 			// Використання стандартного простору імен

class kooClass { // Оголошення класового типу
    int x, y, z; // Тривимірнікоординати; вони тепер закриті
public:
    kooClass(int a, int b, int c) { x = a; y = b; z = c; }
    friend ostream &operator<<(ostream &stream, kooClass obj);
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
    ofstream out("threed");
    if(!out) {
        cout << "Не вдається вiдкрити файл.";
        return 1;
    }
    // Перевизначений оператор виведення даних
    out << ObjA << ObjB << ObjC;

    out.close();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

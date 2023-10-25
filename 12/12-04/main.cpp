//Код програми 12.4. Демонстрація механізму зберігання у векторі об'єктів класу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <vector>				// Для роботи з контейнерним класом "Вектор"

using namespace std; 			// Використання стандартного простору імен

class KooClass { 		// Оголошення класового типу
    int x, y, z; // Тривимірні координати
public:
    KooClass() {x = y = z = 0; }
    KooClass(int a, int b, int c) {x = a; y = b; z = c; }
    // Повертає модифікований об'єкт, адресований вказівником
    KooClass &operator+(int a) { x += a; y += a; z += a; return *this; }
    friend ostream &operator<<(ostream &stream, KooClass ObjA);
    friend bool operator<(KooClass ObjA, KooClass ObjB);
    friend bool operator==(KooClass ObjA, KooClass ObjB);
};
// Відображаємо координати x, y, z за допомогою оператора виведення для класу kooClass
ostream &operator<<(ostream &stream, KooClass ObjA)
{
    stream << "x= " << ObjA.x << ", ";
    stream << "y= " << ObjA.y << ", ";
    stream << "z= " << ObjA.z << endl;
    return stream; // Повертає посилання на параметр stream
}
bool operator<(KooClass ObjA, KooClass ObjB)
{
    return (ObjA.x + ObjA.y + ObjA.z) < (ObjB.x + ObjB.y + ObjB.z);
}
bool operator==(KooClass ObjA, KooClass ObjB)
{
    return (ObjA.x + ObjA.y + ObjA.z) == (ObjB.x + ObjB.y + ObjB.z);
}

int main()
{
    vector<KooClass> vek; // Побудова вектора об'єктів нульової довжини

    // Додаємо у вектор об'єкти.
    for(int i=0; i<10; i++) vek.push_back(KooClass(i, i+2, i-3));

    cout << "Вiдображаємо вмiст початкового вектора" << endl;
    for(int i=0; i<vek.size(); i++) cout << i << " ==> " << vek[i];

    cout << endl;
    // Модифікуємо об'єкти у векторі.

    for(int i=0; i<vek.size(); i++) vek[i] = vek[i] + 10;
    cout << "Вiдображаємо вмiст модифiкованого вектора" << endl;

    for(int i=0; i<vek.size(); i++) cout << i << " ==> " << vek[i];

    //system("PAUSE");
    return EXIT_SUCCESS;
}

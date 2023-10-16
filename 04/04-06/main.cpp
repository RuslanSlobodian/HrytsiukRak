//Код програми 4.6. Демонстрація механізму використання "дружньої" функції класу
//для перевизначення префіксної та постфіксної форми операторів інкремента

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class Coordinates { // Оголошення класового типу
    int x, y, z; // Тривимірні координати
public:
    Coordinates() {x = y = z = 0; }
    Coordinates(int c, int d, int f) {x = c; y = d; z = f; }
    friend Coordinates operator*(Coordinates obi, Coordinates obj);
    Coordinates operator=(Coordinates obj);
    // Ці функції для перевизначення оператора інкремента "++"
    // використовують посилальні параметри.
    friend Coordinates operator++(Coordinates &obi);
    friend Coordinates operator++(Coordinates &obi, int notused);
    void Show(char *s);
};
// Операторна "дружня" функція класу.
Coordinates operator*(Coordinates obi, Coordinates obj)
{
    Coordinates tmp; // Створення тимчасового об'єкта
    tmp.x = obi.x * obj.x;
    tmp.y = obi.y * obj.y;
    tmp.z = obi.z * obj.z;
    return tmp; // Повертає модифікований тимчасовий об'єкт
}
// Перевизначення оператора присвоєння "=".
Coordinates Coordinates::operator=(Coordinates obj)
{
    x = obj.x;
    y = obj.y;
    z = obj.z;
    // Повернення модифікованого об'єкта операнда, адресованого покажчиком
    return *this;
}
/* Перевизначення префіксної форми унарного оператора інкремента "++" з використанням
"дружньої" функції класу. Для цього необхідне використання посилального параметра. */
Coordinates operator++(Coordinates &obi)
{
    obi.x++;
    obi.y++;
    obi.z++;
    return obi;
}
/* Перевизначення постфіксної форми унарного оператора інкремента "++" з використанням
"дружньої" функції класу. Для цього необхідне використання посилального параметра. */
Coordinates operator++(Coordinates &obi, int notused)
{
    Coordinates tmp = obi;
    obi.x++;
    obi.y++;
    obi.z++;
    return tmp; // Повертає модифікований тимчасовий об'єкт
}
// Відображення тривимірних координат x, y, z.
void Coordinates::Show(char *s)
{
    cout << "Координати об'єкта <" << s << ">: ";
    cout << "\t\tx= " << x << ", y= " << y << ", z= " << z << endl;
}

int main()
{
    system("chcp 65001");
    Coordinates ObjA(1, 2, 3), ObjB(10, 10, 10), ObjC;
    ObjA.Show("A");
    ObjB.Show("B");
    ObjC = ObjA * ObjB; // Множення об'єктів ObjA і ObjB
    ObjC.Show("C=A*B");
    ObjC = ObjA * ObjB * ObjC; // Множинне множення об'єктів
    ObjC.Show("c");
    ObjC = ObjB = ObjA ; // Множинне присвоєння об'єктів
    ObjC.Show("C=B");
    ObjB.Show("B=A");
    ++ObjC; // Префіксна форма операції інкремента
    ObjC.Show("++C");
    ObjC++; // Постфіксна версія інкремента
    ObjC.Show("C++");
    ObjA = ++ObjC; // Об'єкт ObjA набуває значення об'єкта ObjC після інкрементування.
    ObjA.Show("A = ++C"); // У цьому випадку об'єкти ObjA і ObjC
    ObjC.Show("C"); // мають однакові значення координат.
    ObjA = ObjC++; // Об'єкт ObjA набуває значення об'єкта ObjC до інкрементування.
    ObjA.Show("A=C++"); // У цьому випадку об'єкти ObjA і ObjC
    ObjC.Show("C"); // мають різні значення координат.

    //system("PAUSE");
    return EXIT_SUCCESS;
}

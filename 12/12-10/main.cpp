//Код програми 12.10. Демонстрація механізму зберігання у списку об'єктів класу

#include <iostream>		// Для потокового введення-виведення
#include <cstdlib>		// Стандартна бібліотека С++
#include <vector>		// Для роботи з контейнерним класом "Вектор"
#include <list> 		// Для роботи зі списками

using namespace std; 			// Використання стандартного простору імен

class MyClass { 		// Оголошення класового типу
    int a, b, sum;
public:
    MyClass() { a = b = 0; }
    MyClass(int c, int d) { a = c; b = d; sum = a + b; }
    int getSum() { return sum; }
    friend bool operator<(const MyClass &ObjA, const MyClass &ObjB);
    friend bool operator>(const MyClass &ObjA, const MyClass &ObjB);
    friend bool operator==(const MyClass &ObjA, const MyClass &ObjB);
    friend bool operator!=(const MyClass &ObjA, const MyClass &ObjB);
};
bool operator<(const MyClass &ObjA, const MyClass &ObjB)
{ return ObjA.sum < ObjB.sum; }
bool operator>(const MyClass &ObjA, const MyClass &ObjB)
{ return ObjA.sum > ObjB.sum; }
bool operator==(const MyClass &ObjA, const MyClass &ObjB)
{ return ObjA.sum == ObjB.sum; }
bool operator!=(const MyClass &ObjA, const MyClass &ObjB)
{ return ObjA.sum != ObjB.sum; }

int main()
{
    list<MyClass> lst1; 	// Створення першого списку.
    for(int i=0; i<10; i++) lst1.push_back(MyClass(i, i));

    cout << "Перший список: ";
    list<MyClass>::iterator p = lst1.begin();
    while(p != lst1.end()) {
        cout << p->getSum() << " ";
        p++;
    }
    cout << endl;

    list<MyClass> lst2; 		// Створення другого списку.
    for(int i=0; i<10; i++) lst2.push_back(MyClass(i*2, i*3));

    cout << "Другий список: ";

    p = lst2.begin();
    while(p != lst2.end()) {
        cout << p->getSum() << " ";
        p++;
    }
    cout << endl;

    // Тепер об'єднуємо списки lst! і lst2.
    lst1.merge(lst2);

    // Відображаємо об'єднаний список.
    cout << "Об'єднаний список: "; p = lst1.begin();
    while(p != lst1.end()) {
        cout << p->getSum() << " ";
        p++;
    }
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

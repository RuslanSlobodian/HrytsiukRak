// Код програми 12.10. Демонстрація механізму зберігання у списку об'єктів класу

#include <iostream>
#include <cstdlib>
#include <list>                 // Для роботи зі списками

using namespace std;

class MyClass {
    int a;
    int b;
    int sum;
public:
    MyClass() { a = b = 0; }

    MyClass(int a, int b) {
        this->a = a;
        this->b = b;
        this->sum = this->a + this->b;
    }

    int getSum() { return sum; }

    friend bool operator<(const MyClass& objectA, const MyClass& objectB);

    friend bool operator>(const MyClass& objectA, const MyClass& objectB);

    friend bool operator==(const MyClass& objectA, const MyClass& objectB);

    friend bool operator!=(const MyClass& objectA, const MyClass& objectB);
};

bool operator<(const MyClass& objectA, const MyClass& objectB) { return objectA.sum < objectB.sum; }

bool operator>(const MyClass& objectA, const MyClass& objectB) { return objectA.sum > objectB.sum; }

bool operator==(const MyClass& objectA, const MyClass& objectB) { return objectA.sum == objectB.sum; }

bool operator!=(const MyClass& objectA, const MyClass& objectB) { return objectA.sum != objectB.sum; }

int main() {
    system("chcp 65001");
    list<MyClass> listA;        // Створення першого списку
    for (int i = 0; i < 10; i++)
        listA.push_back(MyClass(i, i));

    cout << "Перший список: ";
    list<MyClass>::iterator ptr = listA.begin();
    while (ptr != listA.end()) {
        cout << ptr->getSum() << " ";
        ptr++;
    }
    cout << endl;

    list<MyClass> listB;        // Створення другого списку
    for (int i = 0; i < 10; i++)
        listB.push_back(MyClass(i * 2, i * 3));

    cout << "Другий список: ";

    ptr = listB.begin();
    while (ptr != listB.end()) {
        cout << ptr->getSum() << " ";
        ptr++;
    }
    cout << endl;

    // Тепер об'єднуємо списки listA і listB
    listA.merge(listB);

    // Відображаємо об'єднаний список
    cout << "Об'єднаний список: ";
    ptr = listA.begin();
    while (ptr != listA.end()) {
        cout << ptr->getSum() << " ";
        ptr++;
    }
    cout << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

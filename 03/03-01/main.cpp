// Код програми 3.1. Демонстрація механізму використання "дружньої" функції для доступу до закритих членів класу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
    int a;
    int b;
public:
    // Оголошення параметризованого конструктора
    MyClass(int _a, int _b) {
        a = _a;
        b = _b;
    }
    // Функція sum() - "друг" класу MyClass
    friend int sum(MyClass objectB);
};

// Функція sum() не є членом ні одного класу
int sum(MyClass objectB) {
    /*
     * Оскільки функція sum() - "друг" класу MyClass, то вона має
     * право на прямий доступ до його атрибутів a i b
     */
    return objectB.a + objectB.b;
}

int main() {
    MyClass objectA(3, 4);      // Створення об'єкта класу
    cout << "sum = " << sum(objectA) << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

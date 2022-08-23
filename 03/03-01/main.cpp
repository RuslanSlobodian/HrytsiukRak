//Код програми 3.1. Демонстрація механізму використання "дружньої" функції для доступу до закритих членів класу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class myClass { // Оголошення класового типу
    int a, b;
public:
    // Оголошення параметризованого конструктора
    myClass(int _a, int _b) { a = _a; b = _b; }
    friend int Sum(myClass obj); // Функція Sum() - "друг" класу myClass.
};
// Функція Sum() не є членом ні одного класу.
int Sum(myClass obj)
{
    /* Оскільки функція Sum() - "друг" класу myClass, то вона має
     * право на прямий доступ до його членів-даних a i b
    */
    return obj.a + obj.b;
}

int main()
{
    myClass Obj(3, 4); // Створення об'єкта класу
    cout << "Sum= " << Sum(Obj) << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

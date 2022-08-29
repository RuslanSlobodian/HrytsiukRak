// Код програми 2.15. Демонстрація механізму інкрементування та декрементування покажчика на об'єкт

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
    int number;
public:
    void setNumber(int n) { number = n; }
    void showNumber() { cout << "num= " << number << endl; }
};

int main() {
    MyClass object[2];      //Оголошення масиву об'єктів
    MyClass * ptr;          //Оголошення вказівника на об'єкт класу MyClass
    object[0].setNumber(10);     // Прямий доступ до об'єктів
    object[1].setNumber(20);

    ptr = &object[0];       // Отримуємо покажчик на перший елемент
    ptr->showNumber();      // Відображаємо значення елемента object[0] за допомогою вказівника

    ptr++;                  // Переходимо до наступного об'єкта
    ptr->showNumber();      // Відображаємо значення елемента object[1] за допомогою вказівника

    ptr--;                  // Повертаємося до попереднього об'єкта
    ptr->showNumber();      // Знову відображаємо значення елемента object[0]

    //system("PAUSE");
    return EXIT_SUCCESS;
}

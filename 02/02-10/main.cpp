// Код програми 2.10. Демонстрація механізму використання вбудованих функцій у визначенні класу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class MyClass { 			// Оголошення класового типу
    int c; 					// Закритий член за замовчуванням
public:
    // Автоматично вбудовані функції
    void setC(int d) { c = d; }
    int getC() { return c; }
};

int main() {
    MyClass object; 			// Створення об'єкта класу
    object.setC(10);
    cout << "c= " << object.getC() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

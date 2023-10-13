// Код програми 3.16. Демонстрація механізму застосування ключового слова this

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class MyClass {                 // Оголошення класового типу
    int c;
public:
    void setC(int с) {          //сетер (setter) атрибуту с
        this->c = с;
    }
    int getC() {                //гетер (getter) атрибуту с
        return this->c;         // те ж саме, що:  return c;
    }
};

int main() {
    MyClass object;             // Створення об'єкта класу
    object.setC(100);
    cout << "c = " << object.getC() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

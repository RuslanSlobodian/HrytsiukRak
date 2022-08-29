// Код програми 2.6. Демонстрація механізму використання структури для створення класу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 		// Використання стандартного простору імен

struct MyStruct { 			// Оголошення структурного типу
    int get(); 				// Ці члени відкриті (public)
    void set(int d); 		// за замовчуванням
private:
    int c;
};

int MyStruct::get() {
    return c;
}

void MyStruct::set(int d) {
    c = d;
}

int main() {
    MyStruct object; 		// Створення об'єкта структури
    object.set(10);
    cout << "c= " << object.get() << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

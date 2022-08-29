// Код програми 2.8. Демонстрація механізму створення класу на основі об'єднання

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

union MyUnion {                 // Оголошення типу об'єднання
    MyUnion(short int a);       // Відкриті члени за замовчуванням
    short int c;
    char ch[2];

    void show();
};

// Оголошення параметризованого конструктора
MyUnion::MyUnion(short int a) {
    c = a;
}

// Відображення символів, які становлять значення типу short int
void MyUnion::show() {
    cout << ch[0] << " " << ch[1] << endl;
}

int main() {
    MyUnion object(1000);       //Створення об'єкта об'єднання та надання йому числового значення
    object.show();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

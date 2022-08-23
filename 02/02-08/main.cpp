//Код програми 2.8. Демонстрація механізму створення класу на основі об'єднання

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

union myUnion { 			 // Оголошення типу об'єднання
    myUnion(short int a);	 // Відкриті члени за замовчуванням
    void Show();
    short int c;
    char ch[2];
};
// Оголошення параметризованого конструктора
myUnion::myUnion(short int a)
{
    c = a;
}
// Відображення символів, які становлять значення типу short int.
void myUnion::Show()
{
    cout << ch[0] << " " << ch[1] << endl;
}

int main()
{
    myUnion Obj(1000); //Створення об'єкта об'єднання та надання йому числового знач.
    Obj.Show();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

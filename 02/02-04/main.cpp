//Код програми 2.4. Демонстрація механізму передачі конструктору двох параметрів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class widClass { 		       // Оголошення класового типу
private:
    int c, d;
public:
    widClass(int a, int b);  // Оголошення параметризованого конструктора
    void Show();
};
// Передаємо 2 аргументи конструктору widClass().
widClass::widClass(int a, int b)
{
    c = a; d = b;
    cout << "Об'єкт iнiцiалiзовано" << endl;
}

void widClass::Show()
{
    cout << "c= " << c << "; d= " << d << endl;
}

int main()
{
    // Створення та ініціалізація двох об'єктів.
    widClass ObjX(10, 20), ObjY(0, 0);
    ObjX.Show();
    ObjY.Show();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

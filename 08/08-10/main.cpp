//Код програми 8.10. Демонстрація механізму накладання обмежень на тип винятків, які генеруються функцією

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

// Ця функція може генерувати винятки тільки типу int, char і double.
void Xhandler(int test) throw (int, char, double)
{
    if(test == 0) throw test; // Генерує int-винятки
    if(test == 1) throw 'a'; // Генерує char-винятки
    if(test == 2) throw 123.23; // Генерує double-винятки
}
int main()
{
    cout << "Початок" << endl;
    try {
        Xhandler(0); // Спробуйте також передати функції Xhandler() аргументи 1 і 2.
    }
    catch(int c) { cout << "Перехоплення int-винятку" << endl; }
    catch(char c) { cout << "Перехоплення char-винятку" << endl; }
    catch(double d) { cout << "Перехоплення double-винятку" << endl; }

    cout << "Кiнець програми";

    //system("PAUSE");
    return EXIT_SUCCESS;
}

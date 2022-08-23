//Код програми 8.5. Демонстрація механізму перехоплення винятків класового типу

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <string.h>

using namespace std; 			// Використання стандартного простору імен

class myException {
public:
    char str[80];
    myException() { *str = 0; }
    myException(char *s) { strcpy(str, s); }
};
int main()
{
    int a, b;
    try {
        cout << "Введiть чисельник i знаменник: ";
        cin >> a >> b;
        if(!b) throw myException("Дiлити на нуль не можна!");
        else cout << "Частка дорiвнює " << a/b << endl;
    }
    catch(myException e) { // Перехоплення помилки
        cout << e.str << endl;
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

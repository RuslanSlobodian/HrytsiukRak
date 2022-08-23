//Код програми 3.8. Демонстрація механізму використання конструкторів, деструкторів при передачі об'єктів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class myClass { // Оголошення класового типу
    int n;
public:
    myClass(int _n) { n = _n; cout << "Створення об'єкта" << endl; }
    ~myClass() { cout << "Руйнування об'єкта" << endl; }
    int Put() { return n; }
};
void Get(myClass obj)
{
    cout << "n= " << obj.Put() << endl;
}
int main()
{
    myClass ObjA(10); // Створення об'єкта класу
    Get(ObjA);

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 5.2. Демонстраціямеханізму доступу до членів базового класу  після їх успадковується як public-клас

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бiблiотека С++

using namespace std; // Використання стандартного простору iмен

class BaseClass { // Оголошення базового класу
    int c;
    int d;
public:
    void setB(int a, int b) { c = a; d = b; }
    void showB(char *s) {
        cout << s << "c= " << c << "; d= " << d << endl;
    }
};

class Derived : public BaseClass {
    int f;
public:
    Derived(int x) {
        f = x;
    }
    void showF(char *b, char *p) {
        showB(b); cout << p << "f= " << f << endl;
    }
};

int main()
{
    BaseClass objD;

    // Доступ до членiв класу baseClass
    objD.setB(1, 2);
    // Доступ до членiв класу baseClass
    objD.showB("Базовий клас: "); cout << endl;

    // Доступ до члена класу derived
    objD.showF("Базовий клас: ", "Похiдний клас: ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

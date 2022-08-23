//Код програми 5.2. Демонстраціямеханізму доступу до членів базового класу  після їх успадковується як public-клас

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бiблiотека С++

using namespace std; // Використання стандартного простору iмен

class baseClass { // Оголошення базового класу
    int c, d;
public:
    void setB(int a, int b) { c = a; d = b; }
    void showB(char *s)
    { cout << s << "c= " << c << "; d= " << d << endl; }
};

class derived : public baseClass {
    int f;
public:
    derived(int x) { f = x; }
    void showF(char *b, char *p) { showB(b); cout << p << "f= " << f << endl; }
};

int main()
{
    derived ObjD(3);
    // Доступ до членiв класу baseClass
    ObjD.setB(1, 2);
    // Доступ до членiв класу baseClass
    ObjD.showB("Базовий клас: "); cout << endl;

    // Доступ до члена класу derived
    ObjD.showF("Базовий клас: ", "Похiдний клас: ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

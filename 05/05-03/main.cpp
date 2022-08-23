//Код програми 5.3. Демонстраціямеханізму доступу до членів базового класу після їх успадковується як private-клас

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бiблiотека С++

using namespace std; // Використання стандартного простору iмен

class baseClass {		 // Оголошення базового класу
    int c, d;
public:
    void setB(int a, int b) { c = a; d = b; }
    void showB(char *s) { cout << s << "c= " << c << "; d= " << d << endl; }
};
// Вiдкритi члени класу baseClass тепер стають закритими членами класу derived.
class derived : private baseClass {
    int f;
public:
    derived(int x) { f = x; }
    void showF(char *b, char *p) { showB(b); cout << p << "f= " << f << endl; }
};

int main()
{
    derived ObjD(3);
    // Помилка, доступу дофункцiї setB() немає.
    //	ObjD.setB(1, 2);
    // Помилка, доступу дофункцiї showB() немає.
    //	ObjD.showB("Базовий клас: "); cout << endl;

    // Доступ до члена класу derived
    ObjD.showF("Базовий клас: ", "Похiдний клас: ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

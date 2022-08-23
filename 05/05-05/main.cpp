//Код програми 5.5. Демонстрацiя механiзму доступу до захищених членiв базового класу похiдними класами

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бiблiотека С++

using namespace std; // Використання стандартного простору iмен

class baseClass {		 // Оголошення базового класу
protected:
    int c, d;
public:
    void setB(int a, int b) { c = a; d = b; }
    void showB(char *s) { cout << s << "c= " << c << "; d= " << d << 	endl; }
};
// Члени c та d успадковуються як protected-члени.
class derivedA : public baseClass {
    int f;
public:
    void setF() { f = c*d; } // Правомiрний доступ
    void showF(char *b, char *p) { showB(b); cout << p << "f= " << f << endl; }
};
// Члени c та d успадковуються опосередковано черезклас derivedA.
class derivedB : public derivedA {
    int h;
public:
    void setM() { h = c + d; } // Правомiрний доступ
    void showM(char *b, char *p1, char *p2)
    { showF(b, p1); cout << p2 << "h= " << h << endl; }
};

int main()
{
    derivedA ObjA;   // Створення об'єкта класу
    derivedB ObjB;   // Створення об'єкта класу
    ObjA.setB(2, 3);
    ObjA.showB("Базовий клас: "); cout << endl;
    ObjA.setF();
    ObjA.showF("Базовий клас: ", "Похiдний клас: "); cout << endl;
    ObjB.setB(3, 4);
    ObjB.showB("Базовий клас: "); cout << endl;
    ObjB.setF();
    ObjB.setM();
    ObjB.showF("Базовий клас: ", "Похiдний клас 1: "); cout << endl;
    ObjB.showM("Базовий клас: ", "Похiдний клас 1: " , "Похiдний клас 2: ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

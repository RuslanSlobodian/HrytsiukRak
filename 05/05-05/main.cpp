// Код програми 5.5. Демонстрацiя механiзму доступу до захищених членiв базового класу похiдними класами

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бiблiотека С++

using namespace std;            // Використання стандартного простору iмен

class BaseClass {               // Оголошення базового класу
protected:
    int c;
    int d;
public:
    void setBase(int c, int d) {
        this->c = c;
        this->d = d;
    }

    void showBase(string str) const {
        cout << str << "c = " << c << "; d = " << d << endl;
    }
};

// Члени c та d успадковуються як protected-члени
class DerivedA : public BaseClass {
    int f;
public:
    void setF() { f = c * d; } // Правомiрний доступ
    void showDerivedA(string strB, string strD) {
        showBase(strB);
        cout << strD << "f = " << f << endl;
    }
};

// Члени c та d успадковуються опосередковано через клас DerivedA
class DerivedB : public DerivedA {
    int h;
public:
    void setH() { h = c + d; }  // Правомiрний доступ
    void showDerivedB(string strB, string strD1, string strD2) {
        showDerivedA(strB, strD1);
        cout << strD2 << "h = " << h << endl;
    }
};

int main() {
    system("chcp 65001");
    DerivedA objectA;              // Створення об'єкта класу DerivedA
    DerivedB objectB;              // Створення об'єкта класу DerivedB
    objectA.setBase(2, 3);
    objectA.showBase("Базовий клас: ");
    cout << endl;
    objectA.setF();
    objectA.showDerivedA("Базовий клас: ", "Похiдний клас: ");
    cout << endl;
    objectB.setBase(3, 4);
    objectB.showBase("Базовий клас: ");
    cout << endl;
    objectB.setF();
    objectB.setH();
    objectB.showDerivedA("Базовий клас: ", "Похiдний клас 1: ");
    cout << endl;
    objectB.showDerivedB("Базовий клас: ", "Похiдний клас 1: ", "Похiдний клас 2: ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Код програми 5.3. Демонстрація механізму доступу до членів базового класу при успадкуванні з специфікатором private

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бiблiотека С++

using namespace std;            // Використання стандартного простору iмен

class BaseClass {               // Оголошення базового класу
    int c;
    int d;
public:
    void setBase(int c, int d) {
        this->c = c;
        this->d = d;
    }

    void showBase(string str) { cout << str << "c = " << c << "; d = " << d << endl; }
};

// Вiдкритi члени класу BaseClass тепер стають закритими членами класу Derived
class Derived : private BaseClass {
    int f;
public:
    Derived(int f) { this->f = f; }

    void showDerived(string strB, string strD) {
        showBase(strB);
        cout << strD << "f = " << f << endl;
    }
};

int main() {
    system("chcp 65001");
    Derived object(3);
    // Помилка, доступу до методу setBase() немає
//    object.setBase(1, 2);
    // Помилка, доступу до методу showBase() немає
//    object.showBase("Базовий клас: ");
//    cout << endl;

    // Доступ до члена класу Derived
    object.showDerived("Базовий клас: ", "Похiдний клас: ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

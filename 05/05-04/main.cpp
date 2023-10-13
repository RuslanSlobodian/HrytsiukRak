// Код програми 5.4. Демонстрація механізму доступу до захищених членів базового класу

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class BaseClass {               // Оголошення базового класу
protected:
    int c;                      // Ці члени закриті у класі BaseClass,
    int d;                      // але доступні для класу Derived
public:
    void setBase(int c, int d) {
        this->c = c;
        this->d = d;
    }

    void showBase(string str) { cout << str << "c = " << c << "; d = " << d << endl; }
};

// Оголошення похідного класу
class Derived : public BaseClass {
    int f;
public:
    // Клас Derived має доступ до членів класу BaseClass c та d
    void setDerived() { f = c * d; }

    void showDerived(string strB, string strD) {
        showBase(strB);
        cout << strD << "f = " << f << endl;
    }
};

int main() {
    system("chcp 65001");
    Derived object;             // Створення об'єкта класу
    // OK, класу Derived це робити дозволено
    object.setBase(2, 3);
    // OK, класу Derived це робити дозволено
    object.showBase("Базовий клас: ");
    cout << endl;
    // Метод setDerived() належить класу Derived
    object.setDerived();
    // Метод showD() належить класу Derived
    object.showDerived("Базовий клас: ", "Похідний клас: ");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

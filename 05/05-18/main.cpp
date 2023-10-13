// Код програми 5.18. Демонстрація механізму застосування віртуальних базових класів

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class BaseClass {               // Оголошення базового класу
public:
    int c;
};

// Клас DerivedA успадковує клас BaseClass як віртуальний
class DerivedA : virtual public BaseClass {
public:
    int d;
};

// Клас DerivedB успадковує клас baseClass як віртуальний
class DerivedB : virtual public BaseClass {
public:
    int f;
};

// Клас DerivedC успадковує обидва класи DerivedA і DerivedB
// Цього разу він містить тільки одну копію класу BaseClass
class DerivedC : public DerivedA, public DerivedB {
public:
    int sum;
};

int main() {
    DerivedC object;
    object.c = 10;              // Тепер неоднозначності немає
    object.d = 20;
    object.f = 30;

    // Тепер неоднозначності немає
    object.sum = object.c + object.d + object.f;

    // Тепер неоднозначності немає
    cout << object.c << " ";
    cout << object.d << " " << object.f << " ";
    cout << object.sum;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

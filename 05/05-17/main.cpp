// Код програми 5.17. Демонстрація механізму використання оператора дозволу контексту для вибору потрібного члена

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class BaseClass {               // Оголошення базового класу
public:
    int c;
};

// Клас DerivedA успадковує клас BaseClass
class DerivedA : public BaseClass {
public:
    int d;
};

// Клас DerivedB успадковує клас BaseClass
class DerivedB : public BaseClass {
public:
    int f;
};

// Клас DerivedC успадковує обидва класи DerivedA і DerivedB
// Це означає, що у класі DerivedC існує дві копії класу BaseClass!
class DerivedC : public DerivedA, public DerivedB {
public:
    int sum;
};

int main() {
    DerivedC object;

    object.DerivedA::c = 10;    // Контекст дозволений, використовується член c класу DerivedA
    object.d = 20;
    object.f = 30;

    // Контекст дозволений і тут
    object.sum = object.DerivedA::c + object.d + object.f;

    // Виникнення неоднозначності ліквідована також тут
    cout << object.DerivedA::c << " ";
    cout << object.d << " " << object.f << " ";
    cout << object.sum;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

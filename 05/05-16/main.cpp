// Код програми 5.16. Демонстрація невизначеності під час успадкування декількох базових класів

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
    object.c = 10; // Це і є неоднозначність: який саме член c мається на увазі???
    object.d = 20;
    object.f = 30;

    // І тут теж спостерігається неоднозначність з членом c
    object.sum = object.c + object.d + object.f;

    // І тут теж неоднозначність з членом c
    cout << object.c << " ";
    cout << object.d << " " << object.f << " ";
    cout << object.sum;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

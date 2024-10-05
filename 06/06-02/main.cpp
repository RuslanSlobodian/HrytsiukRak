// Код програми 6.2. Демонстрацiя механiзму застосування вiртуальних методів

#include <iostream>
#include <cstdlib>

using namespace std;

class BaseClass {               // Оголошення базового класу
public:
    // Оголошення вiртуального методу
    virtual void show() { cout << "Базовий клас" << endl; }
};

class FirstDerived : public BaseClass {
public:
    // Перевизначення методу show() для класу FirstDerived
    void show() override { cout << "Перший похiдний клас" << endl; }
};

class SecondDerived : public BaseClass {
public:
    // Перевизначення методу show() для класу SecondDerived
    void show() override { cout << "Другий похiдний клас" << endl; }
};

int main() {
    system("chcp 65001");
    BaseClass baseClassObject;  // Створення об'єкта базового класу
    BaseClass* baseClassPtr;    // Створення вказівника на об'єкт базового класу
    FirstDerived firstDerivedObject;    // Створення об'єкта похiдного класу
    SecondDerived secondDerivedObject;  // Створення об'єкта похiдного класу
    baseClassPtr = &baseClassObject;    // Присвоєння вказівнику адреси об'єкта базового класу
    baseClassPtr->show();        // Доступ до методу show() класу BaseClass
    baseClassPtr = &firstDerivedObject; // Присвоєння вказівнику адреси об'єкта першого похiдного класу
    baseClassPtr->show();        // Доступ до методу show() класу FirstDerived
    baseClassPtr = &secondDerivedObject;// Присвоєння вказівнику адреси об'єкта другого похiдного класу
    baseClassPtr->show();        // Доступ до методу show() класу SecondDerived
    cout << "Введіть 1 або 2 щоб створити об'єкт класу FirstDerived або класу SecondDerived відповідно!" << endl;
    int choice;
    cin >> choice;
    switch(choice) {
        case 1:
            baseClassPtr = new FirstDerived();
            break;
        case 2:
            baseClassPtr = new SecondDerived();
            break;
        default:
            cout << "Ви ввели не вірне значення! Буде створено об'єкт базового класу BaseClass!" << endl;
            baseClassPtr = new BaseClass();
    }
    baseClassPtr->show();       // Динамічний поліморфізм

    delete baseClassPtr;
    //system("PAUSE");
    return EXIT_SUCCESS;
}

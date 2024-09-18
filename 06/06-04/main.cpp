// Код програми 6.4. Демонстрація механізму ієрархії успадкування віртуальних методів

#include <iostream>
#include <cstdlib>

using namespace std;

class BaseClass {                // Оголошення базового класу
public:
    virtual void show() { cout << "Базовий клас" << endl; }
};

class FirstDerived : public BaseClass { // Клас FirstDerived виведений з класу BaseClass
public:
    void show() { cout << "Перший похiдний клас" << endl; }
};

class SecondDerived : public FirstDerived { // Клас SecondDerived виведений з класу FirstDerived
    // Метод show() тут взагалі не визначений
};

int main() {
    system("chcp 65001");
    BaseClass baseClassObject;  // Створення об'єкта базового класу
    BaseClass* baseClassPtr;    // Створення вказівника на об'єкт базового класу
    FirstDerived firstDerivedObject;    // Створення об'єкта похiдного класу
    SecondDerived secondDerivedObject;  // Створення об'єкта похiдного класу

    baseClassPtr = &baseClassObject;    // Присвоєння вказівнику адреси об'єкта базового класу
    baseClassPtr->show();       // Доступ до функції show() класу baseClass
    baseClassPtr = &firstDerivedObject; // Присвоєння вказівнику адреси об'єкта похідного класу
    baseClassPtr->show();       // Доступ до функції show() класу FirstDerived
    baseClassPtr = &secondDerivedObject;// Присвоєння вказівнику адреси об'єкта похідного класу
    baseClassPtr->show();       // Тут здійснюється звернення до методу show() класу FirstDerived,
    // оскільки у класі SecondDerived він не перевизначений
    //	system("PAUSE");
    return EXIT_SUCCESS;
}

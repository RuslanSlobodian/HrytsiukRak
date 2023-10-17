// Код програми 6.3. Демонстрація механізму успадкування віртуальних методів

#include <iostream>
#include <cstdlib>

using namespace std;

class BaseClass { 			    // Оголошення базового класу
public:
    virtual void show() { cout << "Базовий клас" << endl; }
};
class FirstDerived : public BaseClass { // Клас FirstDerived виведений з класу BaseClass
public:
    void show() { cout << "Перший похiдний клас" << endl; }
};
class SecondDerived : public BaseClass{ // Клас SecondDerived виведений з класу BaseClass
    // Метод show() тут взагалі не визначений
};
int main()
{
    BaseClass baseClassObject;	// Створення об'єкта базового класу
    BaseClass *baseClassPtr;	// Створення вказівника на об'єкт базового класу
    FirstDerived firstDerivedObject;	// Створення об'єкта похідного класу
    SecondDerived secondDerivedObject; 	// Створення об'єкта похідного класу

    baseClassPtr = &baseClassObject; 		// Присвоєння вказівнику адреси об'єкта базового класу
    baseClassPtr->show(); 		// Доступ до методу show() класу BaseClass
    baseClassPtr = &firstDerivedObject; 	// Присвоєння вказівнику адреси об'єкта похідного класу
    baseClassPtr->show(); 		// Доступ до методу show() класу FirstDerived
    baseClassPtr = &secondDerivedObject; 	// Присвоєння вказівнику адреси об'єкта похідного класу
    baseClassPtr->show();       // Тут здійснюється звернення до методу show() класу BaseClass,
                                // оскільки у класі SecondDerived він не перевизначений
    //system("PAUSE");
    return EXIT_SUCCESS;
}

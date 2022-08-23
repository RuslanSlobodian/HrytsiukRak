//Код програми 10.8. Демонстрація механізму використання оператора dynamic_cast замість оператора typeid

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++
#include <typeinfo> 		// Для динамічної ідентифікації типів

using namespace std; 			// Використання стандартного простору імен

class Base { // Оголошення базового класу
public:
    virtual void Fun() {}
};

class Derived: public Base {
public:
    void derivedOnly() { cout << "Це об'єкт класу Derived" << endl; }
};
int main()
{
    Base *bp, ObjB;
    Derived *dp, ObjD;

    // Використання оператора typeid
    bp = &ObjB; // Присвоєння покажчику адреси об'єкта базового 			класу
    if(typeid(*bp) == typeid(Derived)) {
        dp = (Derived *) bp;
        dp->derivedOnly();
    }
    else
        cout << "Операцiї приведення об'єкта типу Base до "
             << " типу Derived не здiйснено" << endl;

    bp = &ObjD; // Присвоєння покажчику адреси об'єкта 				похідного класу
    if(typeid(*bp) == typeid(Derived)) {
        dp = (Derived *) bp;
        dp->derivedOnly();
    }
    else
        cout << "Помилка, приведення типу має " << "бути реалiзовано!" << endl;
    // Використання оператора dynamic_cast
    bp = &ObjB; // Присвоєння покажчику адреси об'єкта базового 			класу
    dp = dynamic_cast<Derived *> (bp);

    if(dp) dp->derivedOnly();
    else
        cout << "Операцiї приведення об'єкта типу Base до "	<< " типу Derived не здiйснено" << endl;
    bp = &ObjD; // Присвоєння покажчику адреси об'єкта похідного 			классу
    dp = dynamic_cast<Derived *> (bp);
    if(dp) dp->derivedOnly();
    else
        cout << "Помилка, приведення типу має " << "бути реалiзовано!" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

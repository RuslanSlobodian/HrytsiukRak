//Код програми 10.7. Демонстрація різних ситуацій застосування використання оператора dynamic_cast

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class Base {                        // Оголошення базового класу
public:
    virtual void Fun() { cout << "У класi Base" << endl; }
    //. . .
};

class Derived: public Base {
public:
    void Fun() { cout << "У класi Derived" << endl; }
};

int main()
{
    Base *bp, ObjB;
    Derived *dp, ObjD;

    dp = dynamic_cast<Derived *> (&ObjD);
    if(dp) {

        cout << "Приведення типiв " << "(з Derived * у Derived *) реалiзовано" << endl;
        dp->Fun();
    }
    else
        cout << "Помилка" << endl;
    cout << endl;

    bp = dynamic_cast<Base *> (&ObjD);
    if(bp) {
        cout << "Приведення типiв " << "(з Derived * у Base *) реалiзовано" << endl;
        bp->Fun();
    }
    else
        cout << "Помилка" << endl;
    cout << endl;

    bp = dynamic_cast<Base *> (&ObjB);
    if(bp) {
        cout << "Приведення типiв " << "(з Base * у Base *) реалiзовано" << endl;
        bp->Fun();
    }
    else
        cout << "Помилка" << endl;
    cout << endl;

    dp = dynamic_cast<Derived *> (&ObjB);
    if(dp) cout << "Помилка" << endl;
    else
        cout << "Приведення типiв " << "(з Base * у Derived *) не реалiзовано" << endl;
    cout << endl;

    bp = &ObjD; 	// Присвоєння покажчику адреси об'єкта 							   похідного класу
    // bp вказує на об'єкт класу Derived
    dp = dynamic_cast<Derived *> (bp);
    if(dp) {
        cout << "Приведення bp до типу Derived *\n" << "реалiзовано, оскiльки bp дійсно\n"
             << "вказує на об'єкт класу Derived" << endl;
        dp->Fun();
    }
    else
        cout << "Помилка" << endl;
    cout << endl;

    bp = &ObjB; // Присвоєння покажчику адреси об'єкта базового класу
    // bp вказує на об'єкт класу Base
    dp = dynamic_cast<Derived *> (bp);
    if(dp)
        cout << "Помилка";
    else {
        cout << "Тепер приведення bp до типу Derived *\n" << "не реалiзовано, оскiльки bp\n"
             << "насправдi вказує на об'єкт класу Base" << endl;
    }
    cout << endl;

    dp = &ObjD;	 // Присвоєння покажчику адреси об'єкта похідного 					    класу
    // dp вказує на об'єкт класу Derived
    bp = dynamic_cast<Base *> (dp);
    if(bp) {
        cout << "Приведення dp до типу Base * реалiзовано" << endl;
        bp->Fun();
    }
    else
        cout << "Помилка" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

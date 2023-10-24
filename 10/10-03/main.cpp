// Код програми 10.3. Демонстрація механізму застосування оператора typeid до посилального параметра

#include <iostream>
#include <cstdlib>

using namespace std;

class Base {                    // Оголошення базового класу
    virtual void fun() {        // Робимо клас Base поліморфним
        //. . .
    };
};

class DerivedA : public Base {
    //. . .
};

class DerivedB : public Base {
    //. . .
};

// Демонструємо застосування оператора typeid до посилального параметра
void whatType(Base& obj) {
    cout << "Параметр obj посилається на об'єкт типу ";
    cout << typeid(obj).name() << endl;
}

int main() {
    system("chcp 65001");
    Base baseObject;            // Створення об'єкта базового класу
    DerivedA objectA;           // Створення об'єкта похідного класу
    DerivedB objectB;           // Створення об'єкта похідного класу

    whatType(baseObject);
    whatType(objectA);
    whatType(objectB);

    //system("PAUSE");
    return EXIT_SUCCESS;
}

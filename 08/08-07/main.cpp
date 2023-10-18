// Код програми 8.7. Демонстрація механізму перехоплення винятків базовихі похідних типів

#include <iostream>
#include <cstdlib>

using namespace std;

class BaseClass {            // Оголошення базового класу

};

class DerivedClass : public BaseClass {    // Оголошення похідного класу

};

int main() {
    system("chcp 65001");
    DerivedClass derived;
    try {
        throw derived;
    }
    catch (BaseClass object) { cout << "Перехоплення винятку базового класу" << endl; }
    catch (DerivedClass object) { cout << "Це перехоплення не відбудеться" << endl; }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

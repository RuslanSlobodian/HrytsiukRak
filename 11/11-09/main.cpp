// Код програми 11.9. Демонстрація механізму використання статичних членів-даних классу

#include <iostream>
#include <cstdlib>

using namespace std;

class ShareVar {
    static int value;
public:
    void set(int value) { this->value = value; }

    void show() { cout << value << " "; }
};

int ShareVar::value;            // Визначаємо static-член value

int main() {
    ShareVar shareVarA;
    ShareVar shareVarB;

    shareVarA.show();           // Виводиться 0
    shareVarB.show();           // Виводиться 0
    shareVarA.set(10);          // Встановлюємо static-члена value дорівнює 10
    shareVarA.show();           // Виводиться 10
    shareVarB.show();           // Також виводиться 10

    //system("PAUSE");
    return EXIT_SUCCESS;
}

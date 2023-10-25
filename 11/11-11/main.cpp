// Код програми 11.11. Демонстрація механізму використання модифікатора mutable

#include <iostream>
#include <cstdlib>

using namespace std;

class Demo {
    mutable int c;
    int d;
public:
    int getC() const {          // Все гаразд
        return c;
    }

    void setC(int c) const {
        this->c = c;            // Тепер все гаразд
    };

    void setD(int d) const      // Наступний метод не відкомпілюється
    {
//        this->d = d;          // Це, як і раніше, неправильно!
    }
};

int main() {
    Demo object;
    object.setC(1900);
    cout << object.getC();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

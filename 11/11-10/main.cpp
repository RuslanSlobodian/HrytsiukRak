// Код програми 11.10. Демонстрація механізму використання const-функцій-членів класу

#include <iostream>
#include <cstdlib>

using namespace std;

class Demo {
    int value;
public:
    int put() const {
        return value;           // Все гаразд
    }

    void set(int value) const {
//        this->value = value;  // Помилка!
    }
};

int main() {
    Demo object;
    object.set(1900);
    cout << object.put();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

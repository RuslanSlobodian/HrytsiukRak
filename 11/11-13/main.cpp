// Код програми 11.13. Демонстрація механізму використання неявного перетворення конструктора

#include <iostream>
#include <cstdlib>

using namespace std;

class MyClass {
    int с;
public:
    MyClass(int c) {
        this->с = c;
        cout << "Використано параметризований конструктор" << endl;
    }

    int getC() const { return с; }
};

int main() {
    system("chcp 65001");
    MyClass object(10);

    cout << object.getC() << endl;  // Відображає 10
    // Тепер використовуємо неявне перетворення для присвоєння нового значення
    object = 1000;
    cout << object.getC() << endl;  // Відображає 1000

    //system("PAUSE");
    return EXIT_SUCCESS;
}

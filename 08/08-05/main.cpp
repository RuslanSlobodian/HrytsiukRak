// Код програми 8.5. Демонстрація механізму перехоплення винятків класового типу

#include <iostream>
#include <cstdlib>

using namespace std;

class MyException {
    string message;
public:
    MyException() {}

    MyException(string message) {
        this->message = message;
    }

    string getMessage() {
        return this->message;
    }
};

int main() {
    system("chcp 65001");
    int a;
    int b;
    try {
        cout << "Введiть чисельник i знаменник: ";
        cin >> a >> b;
        if (!b) throw MyException("Дiлити на нуль не можна!");
        else cout << "Частка дорiвнює " << a / b << endl;
    }
    catch (MyException e) {     // Перехоплення помилки
        cout << e.getMessage() << endl;
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Код програми 7.5. Демонстрація механізму створення узагальненої версії функції, яка повертає абсолютне значення числа

#include <iostream>
#include <cstdlib>

using namespace std;

template<typename aType>
aType myAbs(aType n) {
    return n < 0 ? -n : n;
}

int main() {
    cout << myAbs(-10) << endl;     // Для типу int
    cout << myAbs(-10.0) << endl;   // Для типу double
    cout << myAbs(-10L) << endl;    // Для типу long
    cout << myAbs(-10.0F) << endl;  // Для типу float
    //system("PAUSE");
    return EXIT_SUCCESS;
}

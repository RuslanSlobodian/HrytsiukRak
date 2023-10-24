// Код програми 10.10. Демонстрація механізму використання оператора static_cast

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int c;
    float f;
    f = 199.22F;
    c = static_cast<int> (f);

    cout << c;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

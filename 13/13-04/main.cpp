// Код програми 13.4. Демонстрація механізму використання директиви #if

#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 100

int main() {
    system("chcp 65001");
#if MAX > 10
    cout << "Потрiбна додаткова память!" << endl;
#endif
    //...

    //system("PAUSE");
    return EXIT_SUCCESS;
}

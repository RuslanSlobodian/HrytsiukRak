// Код програми 13.5. Демонстрація механізму використання директив #if / #else

#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 6

int main() {
    system("chcp 65001");
#if MAX > 10
    cout << "Потрібна додаткова пам'ять" << endl;);
#else
    cout << "Достатньо наявної пам'ятi" << endl;
#endif
    //...

    //system("PAUSE");
    return EXIT_SUCCESS;
}

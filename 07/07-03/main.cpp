// Код програми 7.3. Демонстрація механізму застосування шаблонної функції з двома узагальненими типами

#include <iostream>
#include <cstdlib>

using namespace std;

template<typename aType, typename bType>
void function(aType a, bType b) {
    cout << a << " " << b << endl;
}

int main() {
    system("chcp 65001");
    function(10, "Привiт");
    function(0.23, 10L);
    //system("PAUSE");
    return EXIT_SUCCESS;
}

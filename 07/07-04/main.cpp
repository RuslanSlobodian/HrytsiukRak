// Код програми 7.4. Демонстрація механізму використання стандартних параметрів у шаблонній функції

#include <iostream>
#include <cstdlib>

using namespace std;

template<typename aType>
void repeat(aType data, int times) {
    int tim = times;
    do {
        cout << tim - times + 1 << " ==> " << data << endl;
        times--;
    } while (times);
    cout << endl;
}

int main() {
    system("chcp 65001");
    repeat("Це тест.", 3);
    repeat(100, 5);
    repeat(99.0 / 2, 4);

    //system("PAUSE");
    return EXIT_SUCCESS;
}

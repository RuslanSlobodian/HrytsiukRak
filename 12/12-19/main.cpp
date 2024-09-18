// Код програми 12.19. Демонстрація механізму використання функції find()

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    system("chcp 65001");
    int c;
    string s1 = "Клас string полегшує оброблення рядкiв";
    string s2;

    c = s1.find("string");
    if (c != (int) string::npos) {
        cout << "Збiг виявлений у позицiї " << c << endl;   // 9 бо 4 UTF символи + 1 пробіл
        cout << "Залишок рядка такий: ";
        s2.assign(s1, c, s1.size());
        cout << s2;
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

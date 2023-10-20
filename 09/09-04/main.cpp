// Код програми 9.4. Демонстрація механізму використання функцій flags() і unsetf()

#include <iostream>
#include <cstdlib>

using namespace std;

void showflags(ios::fmtflags f) // Відображення поточного стану опцій
{
    long i;
    for (i = 0x4000; i; i = i >> 1)
        if (i & f) cout << "1 ";
        else cout << "0 ";
    cout << endl;
}

int main() {
    ios::fmtflags flags;        // Оголошення параметру для поточного стану опцій
    flags = cout.flags();       // Отримання поточного стану опцій
    showflags(flags);           // Відображення поточного стану опцій
    cout.setf(ios::showpos);    // Відображення знаку "+" перед позитивним значенням
    cout.setf(ios::scientific); // Відображення чисел у експоненціальному вигляді

    flags = cout.flags();       // Отримання поточного стану опцій
    showflags(flags);           // Відображення поточного стану опцій

    // Скидання опції, що відображає числа в експоненціальному вигляді cout.unsetf(ios::scientific);
    flags = cout.flags();       // Отримання поточного стану опцій
    showflags(flags);           // Відображення поточного стану опцій

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 12.19. Демонстрація механізму використання функції find()

#include <iostream>		 	// Для потокового введення-виведення
#include <cstdlib>			// Стандартна бібліотека С++
#include <string> 			// Для роботи з рядковими типами

using namespace std; 			// Використання стандартного простору імен

int main()
{
    int c;
    string s1 = "Клас string полегшує оброблення рядкiв.";
    string s2;

    c = s1.find("string");
    if(c != string::npos) {
        cout << "Збiг виявлений у позицiї " << c << endl;
        cout << "Залишок рядка такий: ";
        s2.assign(s1, c, s1.size());
        cout << s2;
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

//Код програми 12.13. Демонстрація механізму використання алгоритмів count і count_if

#include <iostream>		// Для потокового введення-виведення
#include <cstdlib>		// Стандартна бібліотека С++
#include <vector> 		// Для роботи з контейнерним класом "Вектор"
#include <algorithm> 	// Для роботи з алгоритмами бібліотеки STL
#include <cctype> 		// Для роботи з символьними аргументами


using namespace std; 			// Використання стандартного простору імен

// Це унарний предикат, який визначає, чи представляє цей символ голосний звук.
// a б в г д е є ж з и і ї й к л м н о п р c т у ф x ц ч ш щ ю я ь

bool isvowel(char ch) {
    ch = tolower(ch);
    if(ch=='а' || ch=='е' || ch=='є' || ch=='и'
            || ch=='і' || ch=='ї' || ch=='о' || ch=='у'
            || ch=='ю' || ch=='я' ) return true;
    return false;
}

int main()
{
    char str[] = "STL-програмування -- це сила!";
    vector<char> vek;
    unsigned int i;

    for(int i=0; str[i]; i++) vek.push_back(str[i]);
    cout << "Послiдовнiсть: ";

    for(int i=0; i<vek.size(); i++) cout << vek[i];
    cout << endl;

    int n; char ch = 'н';
    n = count(vek.begin(), vek.end(), ch);
    cout << n << " символи '" << ch << "'" << endl;

    n = count_if(vek. begin(), vek.end(), isvowel);
    cout << n << " символiв представляють голоснi звуки" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

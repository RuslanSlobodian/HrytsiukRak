//Код програми 2.11. Демонстрація механізму організації масиву об'єктів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

enum resolution {low, medium, high};

class displayClass {	 // Оголошення класового типу
    int width;
    int height;
    resolution res;
public:
    void Set(int w, int h) {width = w; height = h; }
    void Get(int &w, int &h) {w = width; h = height; }
    void Show(resolution r) {res = r; }
    resolution getRes() {return res; }
};

char names[3][9] = { "Низький", "Середнiй", "Високий"};

int main()
{
    displayClass Monitor[3];

    Monitor[0].Show(low);
    Monitor[0].Set(640, 480);

    Monitor[1].Show(medium);
    Monitor[1].Set(800, 600);
    Monitor[2].Show(high);
    Monitor[2].Set(1600, 1200);

    cout << "Можливi режими вiдображення даних: " << endl;

    int w, h;
    for(int i=0; i<3; i++)
    {
        cout << names[Monitor[i].getRes()] << ": ";
        Monitor[i].Get(w, h);
        cout << w << " x " << h << endl;
    }


    //system("PAUSE");
    return EXIT_SUCCESS;
}

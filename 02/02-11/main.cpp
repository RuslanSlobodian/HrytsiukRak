// Код програми 2.11. Демонстрація механізму організації масиву об'єктів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

enum Resolution {low, medium, high};

class DisplayClass {	 // Оголошення класового типу
    int width;
    int height;
    Resolution res;
public:
    void setWidthAndHeight(int w, int h) {width = w; height = h; }
    void getWidthAndHeight(int &w, int &h) {w = width; h = height; }
    void showResolution(Resolution r) {res = r; }
    Resolution getResolution() {return res; }
};

char names[3][12] = { "low", "medium", "high"};

int main() {
    DisplayClass monitors[3];

    monitors[0].showResolution(low);
    monitors[0].setWidthAndHeight(640, 480);

    monitors[1].showResolution(medium);
    monitors[1].setWidthAndHeight(800, 600);
    monitors[2].showResolution(high);
    monitors[2].setWidthAndHeight(1600, 1200);

    cout << "Можливi режими вiдображення даних: " << endl;

    int w, h;
    for(int i=0; i<3; i++) {
        cout << names[monitors[i].getResolution()] << ": ";
        monitors[i].getWidthAndHeight(w, h);
        cout << w << " x " << h << endl;
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

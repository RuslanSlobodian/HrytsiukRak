#include "globalFunctions.h"
#include <iostream>

using namespace std;

void getaLine(string& inStr) // Отримання рядка тексту
{
    char temp[21];
    cin.get(temp, 20, '\n');
    cin.ignore(20, '\n');
    inStr = temp;
}

char getaChar() // Отримання символу
{
    char ch = cin.get();
    cin.ignore(80, '\n');
    return ch;
}

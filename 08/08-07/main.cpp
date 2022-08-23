//Код програми 8.7. Демонстрація механізму перехоплення винятків  базовихі похідних типів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class bClass { 			// Оголошення класового типу

};

class dClass: public bClass { 	// Оголошення класового типу

};

int main()
{
    dClass derived;
    try { throw derived; }
    catch(bClass ObjB) {cout << "Перехоплення винятку базового класу" << endl; }
    catch(dClass ObjD) {cout << "Це перехоплення не відбудеться" << endl; }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

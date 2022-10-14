//Код програми 8.7. Демонстрація механізму перехоплення винятків  базовихі похідних типів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

class SecondClass { 			// Оголошення класового типу

};

class dClass: public SecondClass { 	// Оголошення класового типу

};

int main()
{
    dClass derived;
    try { throw derived; }
    catch(SecondClass ObjB) {cout << "Перехоплення винятку базового класу" << endl; }
    catch(dClass ObjD) {cout << "Це перехоплення не відбудеться" << endl; }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

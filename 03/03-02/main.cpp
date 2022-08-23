//Код програми 3.2. Демонстрація механізму використання "дружньої" функції для перевірки статусу кожного об'єкта

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

const int IDLE=0;
const int INUSE=1;

class bClass; // Випереджувальне оголошення класу
class aClass { // Оголошення класового типу
    int status; // IDLE, якщо повідомлення неактивне
    // INUSE, якщо повідомлення виведене на екран.
public:
    void Set(int s) { status = s; }
    friend int Put(aClass obi, bClass obj);
};

class bClass { // Оголошення класового типу
    int status; // IDLE, якщо повідомлення неактивне
    // INUSE, якщо повідомлення виведене на екран.
public:
    void Set(int s) { status = s; }
    friend int Put(aClass obi, bClass obj);
};

// Функція Put() - "друг" для класів aClass і bClass.
int Put(aClass obi, bClass obj)
{
    if(obi.status || obj.status) return 0;
    else return 1;
}

int main()
{
    aClass ObjX; // Створення об'єкта класу
    bClass ObjY; // Створення об'єкта класу
    ObjX.Set(IDLE); // IDLE = 0
    ObjY.Set(IDLE);
    if(Put(ObjX, ObjY)) cout << "Екран вiльний" << endl;
    else cout << "Вiдображається повiдомлення" << endl;
    ObjX.Set(INUSE); // INUSE = 1
    if(Put(ObjX, ObjY)) cout << "Екран вiльний" << endl;
    else cout << "Вiдображається повiдомлення" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

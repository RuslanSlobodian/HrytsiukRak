//Код програми 3.3. Демонстрація механізму використання функції - члена
//одного класу і одночасно "дружньої функції" - для іншого класу

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
    int Put(bClass obj); // тепер це член класу aClass
};

class bClass { // Оголошення класового типу
    int status; // IDLE, якщо повідомлення неактивне
    // INUSE, якщо повідомлення виведене на екран.
public:
    void Set(int s) { status = s; }
    friend int aClass::Put(bClass obj); // "Дружня" функція класу
};

// Функція Put() -- член класу aClass і "друг" класу bClass.
int aClass::Put(bClass obj)
{
    if(status || obj.status) return 0;
    else return 1;
}

int main()
{
    aClass ObjX; // Створення об'єкта класу
    bClass ObjY; // Створення об'єкта класу
    ObjX.Set(IDLE); // IDLE = 0
    ObjY.Set(IDLE);
    if(ObjX.Put(ObjY)) cout << "Екран вiльний" << endl;
    else cout << "Вiдображається повiдомлення" << endl;
    ObjX.Set(INUSE); // INUSE = 1
    if(ObjX.Put(ObjY)) cout << "Екран вiльний" << endl;
    else cout << "Вiдображається повiдомлення" << endl;

    //system("PAUSE");
    return EXIT_SUCCESS;
}

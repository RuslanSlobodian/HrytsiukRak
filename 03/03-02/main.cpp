// Код програми 3.2. Демонстрація механізму використання "дружньої" функції для перевірки статусу кожного об'єкта

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>				// Стандартна бібліотека С++

using namespace std; 			// Використання стандартного простору імен

const int IDLE  = 0;            // IDLE, якщо повідомлення неактивне
const int INUSE = 1;            // INUSE, якщо повідомлення виведене на екран

class SecondClass;              // Випереджувальне оголошення класу

class FirstClass {              // Оголошення класового типу
    int status;                 // Статус повідомлення
public:
    void setStatus(int s) {
        status = s;
    }
    friend int checkStatus(FirstClass objectA, SecondClass objectB);
};

class SecondClass {             // Оголошення класового типу
    int status;                 // Статус повідомлення
public:
    void setStatus(int s) { status = s; }
    friend int checkStatus(FirstClass objectA, SecondClass objectB);
};

// Функція checkStatus() - "друг" для класів FirstClass і SecondClass
int checkStatus(FirstClass objectA, SecondClass objectB) {
    if(objectA.status || objectB.status) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    FirstClass objectX;         // Створення об'єкта класу FirstClass
    SecondClass objectY;        // Створення об'єкта класу SecondClass

    objectY.setStatus(IDLE);    // IDLE = 0, повідомлення неактивне
    objectY.setStatus(IDLE);    // IDLE = 0, повідомлення неактивне

    if(checkStatus(objectX, objectY)) {
        cout << "Екран вiльний" << endl;
    } else {
        cout << "Вiдображається повiдомлення" << endl;
    }

    objectY.setStatus(INUSE);   // INUSE = 1, повідомлення виведене на екран

    if(checkStatus(objectX, objectY)) {
        cout << "Екран вiльний" << endl;
    } else {
        cout << "Вiдображається повiдомлення" << endl;
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

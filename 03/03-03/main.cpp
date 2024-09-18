/*
 * Код програми 3.3. Демонстрація механізму використання функції - члена
 * одного класу і одночасно "дружньої функції" - для іншого класу
 */

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

const int IDLE = 0;             // IDLE, якщо повідомлення неактивне
const int INUSE = 1;            // INUSE, якщо повідомлення виведене на екран

class SecondClass;              // Випереджувальне оголошення класу

class FirstClass {              // Оголошення класового типу
    int status;                 // Статус повідомлення
public:
    void setStatus(int s) { status = s; }

    int checkStatus(SecondClass object);   // тепер це метод класу FirstClass
};

class SecondClass {             // Оголошення класового типу
    int status;                 // Статус повідомлення
public:
    void setStatus(int s) { status = s; }

    friend int FirstClass::checkStatus(SecondClass object); // Метод класу FirstClass є "другом" класу SecondClass
};

// Метод checkStatus() - член класу FirstClass і "друг" для класу SecondClass
int FirstClass::checkStatus(SecondClass object) {
    if (status || object.status) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    system("chcp 65001");
    FirstClass objectX;         // Створення об'єкта класу
    SecondClass objectY;        // Створення об'єкта класу

    objectX.setStatus(IDLE);    // IDLE = 0, повідомлення неактивне
    objectY.setStatus(IDLE);    // IDLE = 0, повідомлення неактивне

    if (objectX.checkStatus(objectY)) {
        cout << "Екран вiльний" << endl;
    } else {
        cout << "Вiдображається повiдомлення" << endl;
    }

    objectX.setStatus(INUSE);   // INUSE = 1, повідомлення виведене на екран

    if (objectX.checkStatus(objectY)) {
        cout << "Екран вiльний" << endl;
    } else {
        cout << "Вiдображається повiдомлення" << endl;
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}

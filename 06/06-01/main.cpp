// Код програми 6.1. Демонстрація механізму використання вказівників на базовий клас для доступу до об'єктів похідних класів

#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

class BaseClass {               // Оголошення базового класу
    char author[80];
public:
    void setAuthor(const char *author) { strcpy(this->author, author); }

    void showAuthor() { cout << "Автор: " << this->author << endl; }
};

class DerivedClass : public BaseClass { // Оголошення похідного класу
    char title[80];
public:
    void setTitle(const char *title) { strcpy(this->title, title); }

    void showTitle() { cout << "Назва: " << this->title << endl; }
};

int main() {
    system("chcp 65001");
    BaseClass *baseClassPtr;    // Створення вказівника на об'єкт базового класу
    BaseClass baseClassObject;  // Створення об'єкта базового класу
    DerivedClass *derivedClassPtr;      // Створення вказівника на об'єкт похідного класу
    DerivedClass derivedClassObject;    // Створення об'єкта похідного класу
    // Доступ до об'єкта базового класу через вказівник baseClassPtr
    baseClassPtr = &baseClassObject;    // Присвоєння вказівнику адреси об'єкта базового класу

    baseClassPtr->setAuthor("Б'ярн Страуструп");

    // Доступ до об'єкта похідного класу DerivedClass через вказівник на базовий клас
    baseClassPtr = &derivedClassObject; // Присвоєння вказівнику адреси об'єкта похідного класу
    baseClassPtr->setAuthor("Роберт Мартін");

    baseClassObject.showAuthor();       // Покажемо, що кожен автор належить до відповідного об'єкта
    derivedClassObject.showAuthor();
    cout << endl;

    // Оскільки методи setTitle() i showTitle() не є частиною базового класу, то вони не доступні через "базовий" вказівник
    // baseClassPtr, i тому до них потрібно звертатися або безпосередньо, або, як показано тут, через вказівник на похідний клас
    derivedClassPtr = &derivedClassObject;         // Присвоєння вказівнику адреси об'єкта похідного класу
    derivedClassPtr->setTitle("Чистий код");
    derivedClassPtr->showAuthor();      // Тут можна використовувати або вказівник baseClassPtr, або вказівник derivedClassPtr
    derivedClassPtr->showTitle();

    //system("PAUSE");
    return EXIT_SUCCESS;
}

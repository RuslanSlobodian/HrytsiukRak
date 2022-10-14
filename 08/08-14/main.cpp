//Код програми 8.14. Демонстрацiя механiзму перевизначення операторiв new i delete

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бiблiотека С++

using namespace std; 			// Використання стандартного простору iмен

class KooClass { 				// Оголошення класового типу
    int x, y, z; 				// Тривимiрнi координати
public:
    KooClass() { x = y = z = 0; cout << "Створення об'єкта 0, 0, 0" << endl; }
    KooClass(int c, int d, int f) { x = c; y = d; z = f;
                                    cout << "Створення об'єкта " << c << ", ";
                                                                cout << d << ", " << f << endl; }
    ~KooClass() { cout << "Руйнування об'єкта" << endl; }
    void *operator new(size_t size);
    void *operator new[](size_t size);
    void operator delete(void *p);
    void operator delete[](void *p);
    void showB(char *s);
};
// Перевизначення оператора new для класу kooClass.
void *KooClass::operator new(size_t size)
{
    void *p;
    cout << "Видiлення областi пам'ятi для об'єкта класу kooClass" << endl;
    p = malloc(size);

    // Генерування винятку у разi невдалого видiлення областi пам'ятi.
    if(!p) {
        bad_alloc ba;
        throw ba;
    }
    return p;
}
// Перевизначення оператора new для масиву об'єктiв типу kooClass.
void *KooClass::operator new[](size_t size)
{
    void *p;

    cout << "Видiлення областi пам'ятi для масиву kooClass-oб'єктiв" << endl;
    // Генерування винятку при невдачi.
    p = malloc(size);
    if(!p) {
        bad_alloc ba;
        throw ba;
    }
    return p;
}
// Перевизначення оператора delete для класу kooClass.
void KooClass::operator delete(void *p)
{
    cout << "Видалення об'єкта класу kooClass" << endl;
    free(p);
}
// Перевизначення оператора delete для масиву об'єктiв типу kooClass.
void KooClass::operator delete[](void *p)
{
    cout << "Видалення масиву об'єктiв типу kooClass" << endl;
    free(p);
}
// Вiдображення тривимiрних координат x, y, z.
void KooClass::showB(char *s)
{
    cout << "Координати об'єкта <" << s << ">: ";
    cout << "\t\tx= " << x << ", y= " << y << ", z= " << z << endl;
}

int main()
{
    KooClass *p1, *p2;
    try {
        p1 = new KooClass[3]; // Видiлення областi пам'ятi для масиву
        p2 = new KooClass(5, 6, 7); // Видiлення областi пам'ятi для об'єкта
    }
    catch(bad_alloc ba) {
        cout << "Помилка пiд час видiлення областi пам'ятi" << endl;
        return 1;
    }
    p1[1].showB("Базовий клас: ");
    p2->showB("Базовий клас: ");

    delete [] p1; 		// Видалення масиву
    delete p2; 			// Видалення об'єкта

    //system("PAUSE");
    return EXIT_SUCCESS;
}

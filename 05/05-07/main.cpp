// Код програми 5.7. Демонстрація механізму використання специфікатора доступу protected для успадкування базового класу

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бібліотека С++

using namespace std;            // Використання стандартного простору імен

class BaseClass {               // Оголошення базового класу
    int c;                      // Закритий атрибут
protected:
    int d;                      // Захищений атрибут
public:
    int f;                      // Відкритий атрибут
    void setC(int c) { this->c = c; }
    int getC() { return c; }
};

// Успадковуємо клас BaseClass як protected-клас
class Derived : protected BaseClass {
public:
    void setD(int d) { this->d = d; }   // d - тут protected-член
    void setF(int f) { this->f = f; }   // f - тут protected-член
    int getD() { return d; }
    int getF() { return f; }
};

int main() {
    system("chcp 65001");
    Derived object;             // Створення об'єкта класу Derived
    /* Наступний рядок неправомірний, оскільки метод setC() є protected-членом класу derived,
     * що робить його недоступним за його межами */
    //		object.setC(10);
    //    	cout << object.getC(); 	// Неправильно, оскільки метод getC() - protected-член класу
    //		object.f = 10; 	// Неправильно, оскільки атрибут f - protected-член класу

    object.setF(10);
    cout << object.getF() << " ";
    object.setD(12);
    cout << object.getD() << " ";

    system("PAUSE");
    return EXIT_SUCCESS;
}

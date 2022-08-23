//Код програми 5.1. Демонстраціямеханізму успадкування двох підкласів

#include <iostream>		 		// Для потокового введення-виведення
#include <cstdlib>				// Стандартна бiблiотека С++

using namespace std; // Використання стандартного простору iмен

// Оголошення базового класу транспортних засобiв
class dorZasib {
    int kolesa; // Кiлькiсть колiс
    int pasagyr; // Кiлькiсть пасажирiв
public:
    void setKolesa(int f) { kolesa = f; }
    int getKolesa() { return kolesa; }
    void setPasagyr(int t) { pasagyr = t; }
    int getPasagyr() { return pasagyr; }
};

// Оголошення похiдного класу вантажiвок.
class vanAuto : public dorZasib {
    int mistkist; // вантажомiсткiсть умкуб.
public:
    void setMistkist(int h) { mistkist = h; }
    int getMistkist() { return mistkist; }
    void Show(char *s);
};

enum type {car, van, wagon};    // Перерахунковий тип даних

// Оголошення похiдного класу автомобiлiв.
class lehAuto : public dorZasib {
    enum type carType;
public:
    void setType(type t) { carType = t; }
    enum type getType() { return carType; }
    void Show(char *s);
};

void vanAuto::Show(char *s)
{
    cout << "Транспортний засiб: " << s << endl;
    cout << "колiс: " << getKolesa() << " шт" << endl;
    cout << "пасажирiв: " << getPasagyr() << " осiб" << endl;
    cout << "вантажомiсткiсть: " << mistkist << " м куб" << endl;
    cout << endl;
}

void lehAuto::Show(char *s)
{
    cout << "Транспортний засiб: " << s << endl;
    cout << "колiс: " << getKolesa() << " шт" << endl;
    cout << "пасажирiв: " << getPasagyr() << " осiб" << endl;
    cout << "тип: ";
    switch(getType()) {
    case van: cout << "автофургон" << endl;
        break;
    case car: cout << "легковий" << endl;
        break;
    case wagon: cout << "фура" << endl;
    }
    cout << endl;
}

int main()
{
    vanAuto ObjT, ObjF;
    lehAuto ObjG;
    // iнiцiалiзацiя об'єкта типу вантажiвка
    ObjT.setKolesa(18);
    ObjT.setPasagyr(2);
    ObjT.setMistkist(160);
    // iнiцiалiзацiя об'єкта типу вантажiвка
    ObjF.setKolesa(6);
    ObjF.setPasagyr(3);
    ObjF.setMistkist(80);
    // Виведення iнформацiї про об'єкттипу вантажiвка
    ObjT.Show("Вантажiвка 1");
    ObjF.Show("Вантажiвка 2");

    // iнiцiалiзацiя об'єкта типу автомобiль
    ObjG.setKolesa(4);
    ObjG.setPasagyr(6);
    ObjG.setType(van);
    // Виведення iнформацiї про об'єкттипу автомобiль
    ObjG.Show("Автомобiль");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

// Код програми 5.1. Демонстрація механізму успадкування двох підкласів

#include <iostream>             // Для потокового введення-виведення
#include <cstdlib>              // Стандартна бiблiотека С++

using namespace std;            // Використання стандартного простору iмен

// Оголошення базового класу транспортних засобiв
class Vehicle {
    int wheelsNumber;           // Кiлькiсть колiс
    int passengersNumber;       // Кiлькiсть пасажирiв
public:
    void setWheelsNumber(int wheelsNumber) { this->wheelsNumber = wheelsNumber; }

    int getWheelsNumber() const { return wheelsNumber; }

    void setPassengersNumber(int passengersNumber) { this->passengersNumber = passengersNumber; }

    int getPassengersNumber() const { return passengersNumber; }
};

// Оголошення похiдного класу вантажiвок
class Truck : public Vehicle {
    int loadCapacity;           // вантажомiсткiсть у м куб.
public:
    void setLoadCapacity(int loadCapacity) { this->loadCapacity = loadCapacity; }

    int getLoadCapacity() { return loadCapacity; }

    void show(string str);
};

enum class CarType {            // Перечислення CarType
    CAR, VAN, WAGON
};

// Оголошення похiдного класу автомобiлiв
class PassengerCar : public Vehicle {
    CarType carType;
public:
    void setCarType(CarType carType) { this->carType = carType; }

    CarType getCarType() { return carType; }

    void show(string str);
};

void Truck::show(string str) {
    cout << "Транспортний засiб: " << str << endl;
    cout << "колiс: " << getWheelsNumber() << " шт" << endl;
    cout << "пасажирiв: " << getPassengersNumber() << " осiб" << endl;
    cout << "вантажомiсткiсть: " << loadCapacity << " м куб" << endl;
    cout << endl;
}

void PassengerCar::show(string str) {
    cout << "Транспортний засiб: " << str << endl;
    cout << "колiс: " << getWheelsNumber() << " шт" << endl;
    cout << "пасажирiв: " << getPassengersNumber() << " осiб" << endl;
    cout << "тип: ";
    switch (getCarType()) {
        case CarType::VAN:
            cout << "автофургон" << endl;
            break;
        case CarType::CAR:
            cout << "легковий автомобіль" << endl;
            break;
        case CarType::WAGON:
            cout << "універсал" << endl;
    }
    cout << endl;
}

int main() {
    system("chcp 65001");
    Truck truck1;
    Truck truck2;
    PassengerCar car;
    // iнiцiалiзацiя об'єкта типу вантажiвка
    truck1.setWheelsNumber(18);
    truck1.setPassengersNumber(2);
    truck1.setLoadCapacity(160);
    // iнiцiалiзацiя об'єкта типу вантажiвка
    truck2.setWheelsNumber(6);
    truck2.setPassengersNumber(3);
    truck2.setLoadCapacity(80);
    // Виведення iнформацiї про об'єкт типу вантажiвка
    truck1.show("Вантажiвка 1");
    truck2.show("Вантажiвка 2");

    // iнiцiалiзацiя об'єкта типу автомобiль
    car.setWheelsNumber(4);
    car.setPassengersNumber(6);
    car.setCarType(CarType::VAN);
    // Виведення iнформацiї про об'єкт типу автомобiль
    car.show("Автомобiль");

    //system("PAUSE");
    return EXIT_SUCCESS;
}

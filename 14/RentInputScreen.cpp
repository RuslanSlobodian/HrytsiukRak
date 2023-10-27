#include "globalFunctions.h"
#include "RentInputScreen.h"
#include <iostream>

using namespace std;

void RentInputScreen::getRent() {
    cout << "Введiть iм'я мешканця: ";
    getaLine(renterName);
    aptNo = ptrTenantList->getAptNo(renterName);
    if (aptNo > 0) {        // Якщо ім'я знайдене
        // Отримати суму платежу
        cout << "Введiть суму платежу (345.67): ";
        cin >> rentPaid;
        cin.ignore(80, '\n');
        cout << "Введiть номер мiсяця оплати (1-12): ";
        cin >> month;
        cin.ignore(80, '\n');
        month--; // (внутрішня нумерація 0-11)
        ptrRentRecord->insertRent(aptNo, month, rentPaid);
    } else                    // Повернення
        cout << "Такого мешканця немає" << endl;
}

#include "TenantInputScreen.h"
#include "globalFunctions.h"
#include <iostream>

using namespace std;

void TenantInputScreen::getTenant() {   // Отримання даних про мешканцях
    cout << "Введiть iм'я мешканця (Тарас Редько): ";
    getaLine(tName);
    cout << "Введiть номер кiмнати (101): ";
    cin >> aptNo;
    cin.ignore(80, '\n'); // Створити мешканця
    Tenant* ptrTenant = new Tenant(tName, aptNo);
    ptrTenantList->insertTenant(ptrTenant); // Занести перелік мешканців
}
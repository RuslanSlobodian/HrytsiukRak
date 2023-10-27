#include "RentRecord.h"
#include <iostream>

using namespace std;

RentRecord::~RentRecord() {
    while (!setPtrsRR.empty()) {        // Видалити рядки з платежами
        // Видалити вказівника з множини
        iter = setPtrsRR.begin();
        delete *iter;
        setPtrsRR.erase(iter);
    }
}

void RentRecord::insertRent(int aptNo, int month, float amount) {
    RentRow searchRow(aptNo);       // Тимчасовий рядок з тим самим aptNo
    iter = setPtrsRR.begin();       // Пошук setPtrsRR
    while (iter != setPtrsRR.end()) {
        if (searchRow == **iter) {      // RentRow знайдений?
            // так, заносимо
            (*iter)->setRent(month, amount);    // Рядок у перелік
            return;
        } else iter++;
    } // Не знайдений
    RentRow* ptrRow = new RentRow(aptNo);       // Новий рядок
    ptrRow->setRent(month, amount);             // Занести в неї платіж
    setPtrsRR.insert(ptrRow);                // Занести рядок вектор
}

void RentRecord::Display() {
    cout << endl << "AptNo\tСiч Лют Бер Квiт Трав Черв "
         << "Лип Серп Вер Жовт Лист Груд\n"
         << "---------------------------------"
         << "---------------------------------" << endl;
    if (setPtrsRR.empty())
        cout << "***Нема платежiв!***" << endl;
    else {
        iter = setPtrsRR.begin();
        while (iter != setPtrsRR.end())
            cout << **iter++;
    }
}

float RentRecord::getSumOfRents() {     // Сума усіх платежів
    float sumRents = 0.0;
    iter = setPtrsRR.begin();
    while (iter != setPtrsRR.end()) {
        sumRents += (*iter)->getSumOfRow();
        iter++;
    }
    return sumRents;
}

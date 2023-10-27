#include "TenantList.h"
#include <iostream>

using namespace std;

TenantList::~TenantList() {
    while (!setPtrsTens.empty()) {    // Видалення усіх мешканців
        // Видалення вказівників з множини
        iter = setPtrsTens.begin();
        delete *iter;
        setPtrsTens.erase(iter);
    }
}

void TenantList::insertTenant(Tenant* ptrT) {
    setPtrsTens.insert(ptrT); // Вставка
}

int TenantList::getAptNo(const string& tName) // Ім'я присутнє у переліку?
{
    int aptNo;
    Tenant dummy(tName, 0);
    iter = setPtrsTens.begin();
    while (iter != setPtrsTens.end()) {
        aptNo = (*iter)->getAptNumber();    // Пошук мешканця
        if (dummy == **iter++)              // В переліку?
            return aptNo;                   // Так
    }
    return -1;                              // Немає
}

void TenantList::Display() {    // Виведення переліку мешканців
    cout << endl << "Apt#\tIм'я мешканця\n-------------------" << endl;
    if (setPtrsTens.empty())
        cout << "***Нема мешканцiв***" << endl;
    else {
        iter = setPtrsTens.begin();
        while (iter != setPtrsTens.end()) cout << **iter++;
    }
}
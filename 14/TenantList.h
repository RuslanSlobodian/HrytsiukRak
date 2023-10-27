#ifndef LANDLORD_TENANT_LIST_H
#define LANDLORD_TENANT_LIST_H

#include <string>
#include <set>
#include "Tenant.h"

class TenantList {
private:
// Встановити покажчики на мешканців
    std::set<Tenant*, CompareTenants> setPtrsTens;
    std::set<Tenant*, CompareTenants>::iterator iter;
public:
    ~TenantList();         // Оголошення деструктора (Видалення мешканців)
    void insertTenant(Tenant*);         // Внесення мешканця в перелік
    int getAptNo(const std::string&);   // Повертає номер кімнати
    void Display();                     // Виведення переліку мешканців
};

#endif //LANDLORD_TENANT_LIST_H

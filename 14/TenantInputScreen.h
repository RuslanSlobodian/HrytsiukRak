#ifndef LANDLORD_TENANT_INPUT_SCREEN_H
#define LANDLORD_TENANT_INPUT_SCREEN_H

#include "TenantList.h"

class TenantInputScreen {
private:
    TenantList* ptrTenantList;
    std::string tName;
    int aptNo;
public:
    explicit TenantInputScreen(TenantList* ptrTL) : ptrTenantList(ptrTL) {}

    void getTenant();
};


#endif //LANDLORD_TENANT_INPUT_SCREEN_H

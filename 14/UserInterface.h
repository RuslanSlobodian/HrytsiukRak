#ifndef LANDLORD_USER_INTERFACE_H
#define LANDLORD_USER_INTERFACE_H

#include "TenantList.h"
#include "TenantInputScreen.h"
#include "RentRecord.h"
#include "RentInputScreen.h"
#include "ExpenseRecord.h"
#include "AnnualReport.h"
#include "ExpenseInputScreen.h"

class UserInterface {
private:
    TenantList* ptrTenantList;
    TenantInputScreen* ptrTenantInputScreen;
    RentRecord* ptrRentRecord;
    RentInputScreen* ptrRentInputScreen;
    ExpenseRecord* ptrExpenseRecord;
    ExpenseInputScreen* ptrExpenseInputScreen;
    AnnualReport* ptrAnnualReport;
    char ch;
public:
    UserInterface();

    ~UserInterface();

    void interact();
};

#endif //LANDLORD_USER_INTERFACE_H

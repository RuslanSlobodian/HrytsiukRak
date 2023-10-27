#ifndef LANDLORD_RENT_INPUT_SCREEN_H
#define LANDLORD_RENT_INPUT_SCREEN_H

#include <string>
#include "TenantList.h"
#include "RentRecord.h"

class RentInputScreen {
private:
    TenantList* ptrTenantList;
    RentRecord* ptrRentRecord;
    std::string renterName;
    float rentPaid;
    int month;
    int aptNo;
public:
    RentInputScreen(TenantList* ptrTL, RentRecord* ptrRR) :
            ptrTenantList(ptrTL), ptrRentRecord(ptrRR) {}

    void getRent(); // Орендна плата одного мешканця за один місяць
};

#endif //LANDLORD_RENT_INPUT_SCREEN_H

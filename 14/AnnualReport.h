#ifndef LANDLORD_ANNUAL_REPORT_H
#define LANDLORD_ANNUAL_REPORT_H

#include "RentRecord.h"
#include "ExpenseRecord.h"

class AnnualReport {
private:
    RentRecord* ptrRR;
    ExpenseRecord* ptrER;
    float expenses;
    float rents;
public:
    AnnualReport(RentRecord*, ExpenseRecord*);

    void Display();
};

#endif //LANDLORD_ANNUAL_REPORT_H

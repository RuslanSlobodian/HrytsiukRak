#ifndef LANDLORD_RENT_RECORD_H
#define LANDLORD_RENT_RECORD_H

#include <set>
#include "RentRow.h"

class RentRecord {
private:
    // Множини покажчиків на об'єкти RentRow (по одному на мешканця)
    std::set<RentRow*, CompareRows> setPtrsRR;
    std::set<RentRow*, CompareRows>::iterator iter;
public:
    ~RentRecord();

    void insertRent(int, int, float);

    void Display();

    float getSumOfRents(); // Сума усіх платежів
};


#endif //LANDLORD_RENT_RECORD_H
